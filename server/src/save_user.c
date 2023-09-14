/*
** EPITECH PROJECT, 2023
** save
** File description:
** teams
*/

#include "server.h"

void save_user(FILE *fd, user_t *user)
{
    fprintf(fd, "{\n");
    fprintf(fd, "%s\n%s\n", user->id, user->username);
    fprintf(fd, "{\n");
    for (linked_team_t *temp = user->subscribed; temp; temp = temp->next)
        fprintf(fd, "%s\n", temp->ptr->id);
    fprintf(fd, "}\n");
    if (user->current_team)
        fprintf(fd, "%s\n", user->current_team->id);
    else
        fprintf(fd, "NULL\n");
    if (user->current_channel)
        fprintf(fd, "%s\n", user->current_channel->id);
    else
        fprintf(fd, "NULL\n");
    if (user->current_thread)
        fprintf(fd, "%s\n", user->current_thread->id);
    else
        fprintf(fd, "NULL\n");
    fprintf(fd, "}\n");
}
