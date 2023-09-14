/*
** EPITECH PROJECT, 2023
** user_tool
** File description:
** teams
*/

#include "server.h"

int user_online(server_t *server, char *id)
{
    linked_client *temp;

    if (!(server->head))
        return (0);
    for (temp = server->head; temp; temp = temp->next) {
        if (temp->user && strcmp(temp->user->id, id) == 0)
            return (1);
    }
    return (0);
}
