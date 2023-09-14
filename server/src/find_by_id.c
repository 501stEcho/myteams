/*
** EPITECH PROJECT, 2023
** find_by_id
** File description:
** teams
*/

#include "server.h"

user_t *find_user_by_id(linked_user_t *users, char *id)
{
    if (!users)
        return (NULL);
    for (linked_user_t *temp = users; temp; temp = temp->next) {
        if (temp->ptr && strcmp(temp->ptr->id, id) == 0)
            return (temp->ptr);
    }
    return (NULL);
}

team_t *find_team_by_id(linked_team_t *teams, char *id)
{
    if (!teams)
        return (NULL);
    for (linked_team_t *temp = teams; temp; temp = temp->next) {
        if (temp->ptr && strcmp(temp->ptr->id, id) == 0)
            return (temp->ptr);
    }
    return (NULL);
}

channel_t *find_channel_by_id(linked_channel_t *channels, char *id)
{
    linked_channel_t *temp;

    if (!channels)
        return NULL;
    temp = channels;
    while (temp) {
        if (temp->ptr && strcmp(temp->ptr->id, id) == 0)
            return (temp->ptr);
        temp = temp->next;
    }
    return (NULL);
}

thread_t *find_thread_by_id(linked_thread_t *threads, char *id)
{
    linked_thread_t *temp;

    if (!threads)
        return NULL;
    temp = threads;
    while (temp) {
        if (temp->ptr && strcmp(temp->ptr->id, id) == 0)
            return (temp->ptr);
        temp = temp->next;
    }
    return (NULL);
}
