/*
** EPITECH PROJECT, 2023
** list_command
** File description:
** teams
*/

#include "server.h"

void list_team(server_t *server, linked_client *client, char **command)
{
    write_buffer(client->write_buf, LIST_TEAM_S, -1);
    print_teams(client->write_buf, server->teams);
    write_buffer(client->write_buf, "\r\n", -1);
}

void list_chan(server_t *server, linked_client *client, char **command)
{
    if (!user_subscribed(client->user, client->user->current_team))
        return (write_buffer(client->write_buf, UNAUTHORIZED, -1));
    write_buffer(client->write_buf, LIST_CHAN_S, -1);
    print_channel(client->write_buf, client->user->current_team->channels);
    write_buffer(client->write_buf, "\r\n", -1);
}

void list_thread(server_t *server, linked_client *client, char **command)
{
    if (!user_subscribed(client->user, client->user->current_team))
        return (write_buffer(client->write_buf, UNAUTHORIZED, -1));
    write_buffer(client->write_buf, LIST_THR_S, -1);
    print_thread(client->write_buf, client->user->current_channel->threads);
    write_buffer(client->write_buf, "\r\n", -1);
}

void list_reply(server_t *server, linked_client *client, char **command)
{
    if (!user_subscribed(client->user, client->user->current_team))
        return (write_buffer(client->write_buf, UNAUTHORIZED, -1));
    thread_t *curthread = client->user->current_thread;
    write_buffer(client->write_buf, LIST_REP_S, -1);
    print_reply(client->write_buf, curthread->replies);
    write_buffer(client->write_buf, "\r\n", -1);
}

void list_command(server_t *server, linked_client *client, char **command)
{
    int expect[2] = {1, 1};

    if (!check_command_args(client, expect, 1, command))
        return;
    switch (get_context(client->user)) {
        case (home):
            list_team(server, client, command);
            break;
        case (team):
            list_chan(server, client, command);
            break;
        case (channel):
            list_thread(server, client, command);
            break;
        case (thread):
            list_reply(server, client, command);
            break;
    }
}
