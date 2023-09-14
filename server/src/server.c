/*
** EPITECH PROJECT, 2023
** server
** File description:
** myteams
*/

#include "server.h"

// Main et initialisation de la structure serveur

void initialize_fd(int fd, fd_set *read_fd, fd_set *write_fd, fd_set *exe_fd)
{
    FD_ZERO(read_fd);
    FD_ZERO(write_fd);
    FD_ZERO(exe_fd);
    FD_SET(fd, read_fd);
    FD_SET(fd, write_fd);
    FD_SET(fd, exe_fd);
}

void init_commands(server_t *server)
{
    push_command(server->commands, "login", &login_command);
    push_command(server->commands, "logout", &logout_command);
    push_command(server->commands, "use", &use_command);
    push_command(server->commands, "users", &users_command);
    push_command(server->commands, "user", &user_command);
    push_command(server->commands, "send", &send_command);
    push_command(server->commands, "messages", &messages_command);
    push_command(server->commands, "create", &create_command);
    push_command(server->commands, "list", &list_command);
    push_command(server->commands, "subscribed", &subscribed_command);
    push_command(server->commands, "subscribe", &subscribe_command);
    push_command(server->commands, "unsubscribe", &unsubscribe_command);
    push_command(server->commands, "info", &info_command);
}

int bind_and_listen(server_t *server)
{
    struct sockaddr_in sin;
    int len = sizeof(sin);

    server->socket_fd = socket(PF_INET, SOCK_STREAM, 0);
    if (server->socket_fd < 0) {
        printf("Error while creating the socket\n");
        free(server);
        return (-1);
    }
    sin.sin_family = AF_INET;
    sin.sin_port = htons(server->port);
    sin.sin_addr.s_addr = INADDR_ANY;
    if (bind(server->socket_fd, (struct sockaddr *)(&sin), len) < 0)
        return (emit_error(server, "Bind failed"));
    if (listen(server->socket_fd, 25) < 0)
        return (emit_error(server, "Listen failed"));
    initialize_fd(server->socket_fd, &server->read_fd, &server->write_fd,
        &server->exe_fd);
    return (0);
}

int main(int argc, char **argv)
{
    server_t *server;

    handle_args(argc, argv, &server);
    load_backup(server);
    if (bind_and_listen(server) < 0)
        return (84);
    mainloop(server);
}
