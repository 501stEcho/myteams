/*
** EPITECH PROJECT, 2023
** creates
** File description:
** commandes
*/

#include "server.h"

void create_team(server_t *server, linked_client *client, char **command)
{
    team_t *nteam;
    if (tab_len(command) != 3)
        return;
    if (find_team_by_name(server->teams, command[1]) != NULL)
        return (write_buffer(client->write_buf, ALREADY_EXIST, -1));
    nteam = init_team(command[1], command[2]);
    push_team(&server->teams, nteam);
    server_event_team_created(nteam->id, nteam->name, client->user->id);
    send_all_users(server, format_three_string(CREATE_TEAM_S, nteam->id,
        nteam->name, nteam->description));
}

void create_chan(server_t *server, linked_client *client, char **command)
{
    channel_t *nchan;
    if (tab_len(command) != 3)
        return;
    if (!user_subscribed(client->user, client->user->current_team))
        return (write_buffer(client->write_buf, UNAUTHORIZED, -1));
    if (find_channel_by_name(client->user->current_team->channels,
        command[1]) != NULL)
        return (write_buffer(client->write_buf, ALREADY_EXIST, -1));
    nchan = init_channel(command[1], command[2]);
    push_channel(&client->user->current_team->channels, nchan);
    server_event_channel_created(client->user->current_team->id,
        nchan->id, nchan->name);
    send_all_team_users(server, client->user->current_team,
    format_three_string(CREATE_CHAN_S, nchan->id,
    nchan->name, nchan->description));
}

void create_thread(server_t *server, linked_client *client, char **command)
{
    thread_t *nthread;
    if (tab_len(command) != 3)
        return;
    if (!user_subscribed(client->user, client->user->current_team))
        return (write_buffer(client->write_buf, UNAUTHORIZED, -1));
    if (find_thread_by_name(client->user->current_channel->threads,
        command[1]) != NULL)
        return (write_buffer(client->write_buf, ALREADY_EXIST, -1));
    nthread = init_thread(command[1], command[2], client->user->id);
    push_thread(&client->user->current_channel->threads, nthread);
    server_event_thread_created(client->user->current_channel->id, nthread->id,
        client->user->id, nthread->title, nthread->message);
    send_all_team_users(server, client->user->current_team,
    describe_thread(CREATE_THR_S, nthread));
}

void create_reply(server_t *server, linked_client *client, char **command)
{
    reply_t *nreply;
    if (tab_len(command) != 2)
        return;
    if (!user_subscribed(client->user, client->user->current_team))
        return (write_buffer(client->write_buf, UNAUTHORIZED, -1));
    nreply = init_reply(client->user->id, command[1],
        client->user->current_thread->id, client->user->current_team->id);
    push_reply(&client->user->current_thread->replies, nreply);
    server_event_reply_created(client->user->current_thread->id,
        client->user->id, nreply->message);
    send_all_team_users(server, client->user->current_team,
    describe_reply(CREATE_REP_S, nreply));
}

void create_command(server_t *server, linked_client *client, char **command)
{
    if (!client->user)
        return (write_buffer(client->write_buf, UNAUTHORIZED, -1));
    switch (get_context(client->user)) {
        case (home):
            create_team(server, client, command);
            break;
        case (team):
            create_chan(server, client, command);
            break;
        case (channel):
            create_thread(server, client, command);
            break;
        case (thread):
            create_reply(server, client, command);
            break;
    }
}
