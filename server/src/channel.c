/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

channel_t *init_channel(char *name, char *description)
{
    channel_t *new = malloc(sizeof(channel_t));
    uuid_t uid;

    new->id = malloc(37 * sizeof(char));
    uuid_generate(uid);
    uuid_unparse_lower(uid, new->id);
    new->name = strdup(name);
    new->description = strdup(description);
    new->threads = NULL;
    return (new);
}

void destroy_channel(channel_t *team)
{
    free(team->id);
    free(team->name);
    free(team->description);
    free(team);
}
