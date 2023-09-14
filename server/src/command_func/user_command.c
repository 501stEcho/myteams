/*
** EPITECH PROJECT, 2023
** user_command
** File description:
** myteams
*/

#include "server.h"

void users_command(server_t *server, linked_client *client, char **command)
{
    char *src;
    int n, args[] = {1, 1};

    if (!check_command_args(client, args, 1, command))
        return;
    write_buffer(client->write_buf, USER_LIST_S, -1);
    if (server->users)
        print_users(client->write_buf, server->users);
    write_buffer(client->write_buf, "\r\n", -1);
}

void user_command(server_t *server, linked_client *client, char **command)
{
    user_t *target;
    char *src;
    int args[] = {2, 2};
    int n;

    if (!check_command_args(client, args, 1, command))
        return;
    target = find_user_by_id(server->users, command[1]);
    if (target) {
        write_buffer(client->write_buf, USER_DETAIL_S, -1);
        detail_user(client->write_buf, target);
        write_buffer(client->write_buf, "\r\n", 2);
    } else
        write_buffer(client->write_buf,
            format_one_string(UNKNOW_USER, command[1]), -1);
}
