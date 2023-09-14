/*
** EPITECH PROJECT, 2023
** mainloop
** File description:
** ftp
*/

#include "server.h"

// boucle principale où on check si un nouveau client s'est connecté
// et si un client a envoyé une commande

int add_new_client(server_t *server, int client_fd)
{
    linked_client *new = create_elem(client_fd);

    FD_SET(client_fd, &(server->read_fd));
    FD_SET(client_fd, &(server->write_fd));
    FD_SET(client_fd, &(server->exe_fd));
    write_buffer(new->write_buf, "220\nService ready for new user.\r\n", -1);
    push_back(&server->head, new);
    return (0);
}

int check_new_client(server_t *server, fd_set *read_fd)
{
    int client_fd;
    struct sockaddr_in sin;
    int len = sizeof(sin);

    if (FD_ISSET(server->socket_fd, read_fd)) {
        client_fd = accept(server->socket_fd, (struct sockaddr *)&sin,
            (socklen_t *)&len);
        if (client_fd > 0) {
            add_new_client(server, client_fd);
        } else {
            perror("Accept failed");
            return (-1);
        }
    }
}

int check_client_write(server_t *server, fd_set *write_fd,
    linked_client *client)
{
    char *msg;

    if (FD_ISSET(client->fd, write_fd)) {
        msg = read_buffer(client->write_buf);
        write_message(client->fd, msg);
        free(msg);
        FD_CLR(client->fd, write_fd);
    }
}

int mainloop(server_t *server)
{
    linked_client *save;
    fd_set tmp_rd_fd;
    fd_set tmp_wt_fd;
    fd_set tmp_ex_fd;

    while (1) {
        tmp_rd_fd = server->read_fd;
        tmp_wt_fd = server->write_fd;
        tmp_ex_fd = server->exe_fd;
        if (select(FD_SETSIZE, &tmp_rd_fd, &tmp_wt_fd, &tmp_ex_fd, NULL) < 0)
            exit(84);
        check_new_client(server, &tmp_rd_fd);
        for (linked_client *temp = server->head; temp != NULL;
            temp = save) {
            save = temp->next;
            check_client_write(server, &tmp_wt_fd, temp);
            check_client_read(server, &tmp_rd_fd, temp);
        }
    }
}
