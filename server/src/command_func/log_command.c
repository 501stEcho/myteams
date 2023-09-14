/*
** EPITECH PROJECT, 2023
** log_command
** File description:
** myteams
*/

#include "server.h"

void login_command(server_t *server, linked_client *client, char **command)
{
    user_t *new;
    int args[] = {2, 2};
    char *src;
    int n;
    if (!check_command_args(client, args, 0, command))
        return;
    client->user = find_user_by_name(server->users, command[1]);
    if (!client->user) {
        new = init_user(command[1]);
        push_user(&server->users, new);
        client->user = new;
        server_event_user_created(new->id, new->username);
    }
    client->user->tracker++;
    src = format_two_string(LOGIN_S, client->user->id, client->user->username);
    send_all_users(server, src);
    server_event_user_logged_in(client->user->id);
}

void logout_command(server_t *server, linked_client *client, char **command)
{
    int args[] = {1, 1};
    char *src;
    int n;

    if (!check_command_args(client, args, 1, command))
        return;
    src = format_two_string(LOGOUT_S, client->user->id, client->user->username);
    send_all_users(server, src);
    server_event_user_logged_out(client->user->id);
    client->user->tracker--;
    client->user = NULL;
}
