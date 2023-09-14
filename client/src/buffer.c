/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** buffer
*/

#include "client.h"

void add_to_buff(client_t *client, char buffer[1024])
{
    client->head_socket = client->read_socket;
    for (int i = 0; buffer[i] != '\0'; i++,
    client->read_socket = R_BUFF(client->read_socket, 1))
        client->buff_socket[client->read_socket] = buffer[i];
    client->buff_socket[client->read_socket] = '\0';
}

void read_client(client_t *client)
{
    int sd = client->socket_fd;
    char buffer[1024];
    int valread = 0;

    if ((valread = read(sd, buffer, 1024)) != 0) {
        buffer[valread] = '\0';
        add_to_buff(client, buffer);
    }
}

int write_message(int client_fd, char *msg)
{
    if (!msg)
        return (0);
    if (write(client_fd, msg, strlen(msg)) < 0) {
        perror("Write failed");
        return (84);
    }
}
