/*
** EPITECH PROJECT, 2023
** myteams
** File description:
** myteams
*/

#include "server.h"

int valid_format(char *str)
{
    int i = 0;

    if (strlen(str) < 3)
        return (0);
    if (strcmp(&str[strlen(str) - 2], "\r\n") != 0)
        return (0);
    if (str[0] != '/')
        return (0);
    return (1);
}

int find_command(server_t *server, linked_client *client, char **command)
{
    int len = tab_len(command);
    command_t *temp;

    for (temp = *(server->commands); temp; temp = temp->next) {
        if (strcmp(command[0], temp->name) == 0) {
            (*(temp->ptr))(server, client, command);
            return (0);
        }
    }
    return (-1);
}

void interpret_command(server_t *server, linked_client *client, char *line)
{
    char **command;

    if (!valid_format(line))
        return;
    line[strlen(line) - 2] = 0;
    if (!valid_command_format(line))
        return;
    command = split_command(line);
    if (!command)
        return;
    if (find_command(server, client, command) < 0)
        return;
}

int check_client_read(server_t *server, fd_set *read_fd, linked_client *client)
{
    char buffer[500];
    char **commands = NULL;
    int res = 0;

    if (client->quitting == 1) {
        FD_CLR(client->fd, &(server->read_fd));
        FD_CLR(client->fd, &(server->write_fd));
        FD_CLR(client->fd, &(server->exe_fd));
        pop_client(&(server->head), client);
        return (0);
    }
    if (FD_ISSET(client->fd, read_fd)) {
        res = read(client->fd, buffer, 500);
        write_buffer(client->read_buf, buffer, res);
        commands = get_command(client->read_buf);
        FD_CLR(client->fd, read_fd);
    }
    for (int i = 0; commands && commands[i]; i++) {
        interpret_command(server, client, commands[i]);
    }
}

int check_command_args(linked_client *client, int arg_nb[2], int auth,
    char **command)
{
    if (auth && !(client->user)) {
        write_buffer(client->write_buf, UNAUTHORIZED, -1);
        return (0);
    }
    if (tab_len(command) < arg_nb[0] || tab_len(command) > arg_nb[1]) {
        return (0);
    }
    return (1);
}
