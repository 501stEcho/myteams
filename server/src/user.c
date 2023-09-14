/*
** EPITECH PROJECT, 2023
** linked_user
** File description:
** myteams
*/

#include "server.h"

user_t *init_user(char *username)
{
    user_t *new = malloc(sizeof(user_t));
    uuid_t uid;

    new->id = malloc(37 * sizeof(char));
    uuid_generate(uid);
    uuid_unparse_lower(uid, new->id);
    new->contxt = home;
    new->username = strdup(username);
    new->current_team = NULL;
    new->current_channel = NULL;
    new->current_thread = NULL;
    new->tracker = 0;
    new->subscribed = NULL;
    return (new);
}

void destroy_user(user_t *user)
{
    free(user->username);
    free(user);
}

int user_subscribed(user_t *user, team_t *team)
{
    if (!team || !user)
        return (0);
    for (linked_team_t *temp = user->subscribed; temp; temp = temp->next) {
        if (strcmp(temp->ptr->id, team->id) == 0)
            return (1);
    }
    return (0);
}
