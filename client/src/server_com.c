/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** main
*/

#include "../include/client.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

int send_server_command(client_t *client)
{
    char *cmd = getcmd();

    if (strncmp(cmd, "/help\n", 6) == 0)
        printf(HELPP);
    else {
        cmd = good_str(cmd, "\r\n", 1);
        write_buffer(client->write_buf, cmd, strlen(cmd));
    }
    return 0;
}

int check_server_write(client_t *client, fd_set *write_fd)
{
    char *msg;

    if (FD_ISSET(client->socket_fd, write_fd)) {
        msg = read_buffer(client->write_buf);
        write_message(client->socket_fd, msg);
        free(msg);
        FD_CLR(client->socket_fd, write_fd);
    }
}

int check_server_response(client_t *client, fd_set *read_fd)
{
    char buffer[500];
    int res;

    if (FD_ISSET(client->socket_fd, read_fd)) {
        res = read(client->socket_fd, buffer, 500);
        write_buffer(client->read_buf, buffer, res);
        FD_CLR(client->socket_fd, read_fd);
        read_server_response(client);
    }
}

int read_server_response(client_t *client)
{
    char ***tmp;
    char *buff = read_buffer(client->read_buf);

    if (!buff)
        return (0);
    to_triple_star(buff);
    free(buff);
    return 0;
}
