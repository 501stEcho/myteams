/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** main
*/

#include "../include/client.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <unistd.h>

int init_struct(client_t *client, int ac, char **av)
{
    client->ac = ac;
    client->av = av;
    client->buff_socket = malloc((2001) * sizeof(char *));
    client->buff_socket[2000] = 0;
    client->len_socket = 2000;
    client->head_socket = 0;
    client->read_socket = 0;
    client->buff_stdin = malloc((2001) * sizeof(char *));
    client->buff_stdin[2000] = 0;
    client->len_stdin = 2000;
    client->head_stdin = 0;
    client->read_stdin = 0;
    client->tab = NULL;
    client->port = atoi(client->av[2]);
    client->ip = client->av[1];
    client->write_buf = create_buffer(2000);
    client->read_buf = create_buffer(2000);
}

void initialize_fd(int fd, fd_set *read_fd, fd_set *write_fd, fd_set *exe_fd)
{
    FD_ZERO(read_fd);
    FD_ZERO(write_fd);
    FD_ZERO(exe_fd);
    FD_SET(fd, read_fd);
    FD_SET(fd, write_fd);
    FD_SET(fd, exe_fd);
    FD_SET(STDIN_FILENO, read_fd);
}

int client_loop(client_t *client)
{
    fd_set tmp_rd_fd;
    fd_set tmp_wt_fd;
    fd_set tmp_ex_fd;

    while (1) {
        tmp_rd_fd = client->read_fd;
        tmp_wt_fd = client->write_fd;
        tmp_ex_fd = client->exe_fd;
        if (select(FD_SETSIZE, &tmp_rd_fd, &tmp_wt_fd, &tmp_ex_fd, NULL) < 0)
            exit(84);
        if (FD_ISSET(STDIN_FILENO, &tmp_rd_fd))
            send_server_command(client);
        check_server_write(client, &tmp_wt_fd);
        check_server_response(client, &tmp_rd_fd);
    }
    return 0;
}

int client_start(int ac, char **av)
{
    client_t *client = malloc(sizeof(client_t));;

    init_struct(client, ac, av);
    if ((client->socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        exit(84);
    client->adress.sin_family = AF_INET;
    client->adress.sin_addr.s_addr = inet_addr(client->ip);
    client->adress.sin_port = htons(client->port);
    if (connect(client->socket_fd, (struct sockaddr *)&client->adress,
                sizeof(client->adress)) < 0) {
        shutdown(client->socket_fd, SHUT_RDWR);
        free(client);
        exit(84);
    }
    initialize_fd(client->socket_fd, &client->read_fd, &client->write_fd,
    &client->exe_fd);
    client_loop(client);
    return 0;
}
