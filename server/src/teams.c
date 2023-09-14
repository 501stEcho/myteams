/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

team_t *init_team(char *name, char *description)
{
    team_t *new = malloc(sizeof(team_t));
    uuid_t uid;

    new->id = malloc(37 * sizeof(char));
    uuid_generate(uid);
    uuid_unparse_lower(uid, new->id);
    new->name = strdup(name);
    new->description = strdup(description);
    new->channels = NULL;
    new->subscribed = NULL;
    return (new);
}

void destroy_team(team_t *team)
{
    free(team->id);
    free(team->name);
    free(team->description);
    free(team);
}
