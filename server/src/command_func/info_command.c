/*
** EPITECH PROJECT, 2023
** info command
** File description:
** myteams
*/

#include "server.h"

void info_thread(linked_client *client, thread_t *thread)
{
    if (!thread)
        return;
    write_buffer(client->write_buf, SELECT_REP_DET_S, -1);
    detail_thread(client->write_buf, thread);
    write_buffer(client->write_buf, "\r\n", 2);
}

void info_channel(linked_client *client, channel_t *channel)
{
    if (!channel)
        return;
    write_buffer(client->write_buf, SELECT_CHAN_DET_S, -1);
    detail_channel(client->write_buf, channel);
    write_buffer(client->write_buf, "\r\n", 2);
}

void info_team(linked_client *client, team_t *team)
{
    if (!team)
        return;
    write_buffer(client->write_buf, SELECT_TEAM_DET_S, -1);
    detail_team(client->write_buf, team);
    write_buffer(client->write_buf, "\r\n", 2);
}

void info_user(linked_client *client, user_t *user)
{
    if (!user)
        return;
    write_buffer(client->write_buf, LOGIN_USR_DET_S, -1);
    detail_user(client->write_buf, user);
    write_buffer(client->write_buf, "\r\n", 2);
}

void info_command(server_t *server, linked_client *client, char **command)
{
    int expect[2] = {1, 1};

    if (!check_command_args(client, expect, 1, command))
        return;
    switch (get_context(client->user)) {
        case (home):
            info_user(client, client->user);
            break;
        case (team):
            info_team(client, client->user->current_team);
            break;
        case (channel):
            info_channel(client, client->user->current_channel);
            break;
        case (thread):
            info_thread(client, client->user->current_thread);
            break;
    }
}
