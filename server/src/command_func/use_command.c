/*
** EPITECH PROJECT, 2023
** use
** File description:
** command
*/

#include "server.h"

int check_thread(channel_t *origin, linked_client *client, thread_t **buf,
    char **command)
{
    if (tab_len(command) < 4 || !origin) {
        *buf = NULL;
        return (0);
    }
    *buf = find_thread_by_id(origin->threads, command[3]);
    if (!(*buf))
        return (-1);
    return (0);
}

int check_channel(team_t *origin, linked_client *client, channel_t **buf,
    char **command)
{
    if (tab_len(command) < 3 || !origin) {
        *buf = NULL;
        return (0);
    }
    *buf = find_channel_by_id(origin->channels, command[2]);
    if (!(*buf))
        return (-1);
    return (0);
}

int check_team(linked_team_t *origin, linked_client *client, team_t **buf,
    char **command)
{
    if (tab_len(command) < 2 || !origin) {
        *buf = NULL;
        return (0);
    }
    *buf = find_team_by_id(origin, command[1]);
    if (!client || !client->user || !user_subscribed(client->user, *buf)) {
        write_buffer(client->write_buf, UNAUTHORIZED, -1);
        return (-1);
    }
    if (!(*buf))
        return (-1);
    return (0);
}

void use_command(server_t *server, linked_client *client, char **command)
{
    int args[] = {1, 4};
    int arg_nb = tab_len(command);
    team_t *tm_tmp;
    channel_t *ch_tmp;
    thread_t *tr_tmp;

    if (!check_command_args(client, args, 1, command))
        return;
    if (!(check_team(server->teams, client, &tm_tmp, command) < 0 ||
        check_channel(tm_tmp, client, &ch_tmp, command) < 0 ||
        check_thread(ch_tmp, client, &tr_tmp, command) < 0)) {
        set_context(client->user, tm_tmp, ch_tmp, tr_tmp);
    }
}

void set_context(user_t *user, team_t *team, channel_t *channel,
    thread_t *thread)
{
    user->current_team = team;
    user->current_channel = channel;
    user->current_thread = thread;
}
