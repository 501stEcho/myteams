/*
** EPITECH PROJECT, 2023
** subscribe_command
** File description:
** myteams
*/

#include "server.h"

void subscribe_command(server_t *server, linked_client *client, char **command)
{
    int args[] = {2, 2};
    team_t *target;
    if (!check_command_args(client, args, 1, command))
        return;
    target = find_team_by_id(server->teams, command[1]);
    if (target) {
        push_team(&client->user->subscribed, target);
        push_user(&target->subscribed, client->user);
        write_buffer(client->write_buf, format_two_string(SUB_S,
            client->user->id, target->id), -1);
        server_event_user_subscribed(target->id, client->user->id);
    } else {
        write_buffer(client->write_buf,
            format_one_string(UNKNOW_TEAM, command[1]), -1);
    }
}

void subscribed_command(server_t *server, linked_client *client,
    char **command)
{
    int args[] = {1, 2};
    char *src;
    team_t *target;
    if (!check_command_args(client, args, 1, command))
        return;
    if (tab_len(command) == 1) {
        write_buffer(client->write_buf, SUB_TEAMS_S, -1);
        print_teams(client->write_buf, client->user->subscribed);
        write_buffer(client->write_buf, "\r\n", 2);
    } else {
        target = find_team_by_id(server->teams, command[1]);
        if (target) {
            write_buffer(client->write_buf, SUB_LIST_S, -1);
            print_users(client->write_buf, target->subscribed);
            write_buffer(client->write_buf, "\r\n", 2);
        } else {
            write_buffer(client->write_buf,
                format_one_string(UNKNOW_TEAM, command[1]), -1);
        }
    }
}

void unsubscribe_command(server_t *server, linked_client *client,
    char **command)
{
    int args[] = {2, 2};
    team_t *targetteam;

    if (!check_command_args(client, args, 1, command))
        return;
    targetteam = find_team_by_id(client->user->subscribed, command[1]);
    if (!targetteam || !find_user_by_id(targetteam->subscribed,
        client->user->id)) {
        return (write_buffer(client->write_buf,
        format_one_string(UNKNOW_TEAM, command[1]), -1));
    }
    pop_team(&client->user->subscribed, targetteam);
    pop_user(&targetteam->subscribed, client->user);
    write_buffer(client->write_buf, format_two_string(UNSUB_S,
        client->user->id, targetteam->id), -1);
    server_event_user_unsubscribed(targetteam->id, client->user->id);
}
