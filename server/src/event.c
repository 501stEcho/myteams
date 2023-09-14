/*
** EPITECH PROJECT, 2023
** event
** File description:
** teams
*/

#include "server.h"

void send_all_users(server_t *server, char *msg)
{
    for (linked_client *temp = server->head; temp; temp = temp->next) {
        if (temp->user) {
            write_buffer(temp->write_buf, msg, -1);
        }
    }
}

void send_all_team_users(server_t *server, team_t *team, char *msg)
{
    for (linked_client *temp = server->head; temp; temp = temp->next) {
        if (temp->user && user_subscribed(temp->user, team)) {
            write_buffer(temp->write_buf, msg, -1);
        }
    }
}

void send_to_user(server_t *server, char *uuid, char *msg)
{
    for (linked_client *temp = server->head; temp; temp = temp->next) {
        if (temp->user && strcmp(temp->user->id, uuid) == 0) {
            write_buffer(temp->write_buf, msg, -1);
        }
    }
}
