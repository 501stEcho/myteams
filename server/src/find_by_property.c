/*
** EPITECH PROJECT, 2023
** find_by_property
** File description:
** teams
*/

#include "server.h"

user_t *find_user_by_name(linked_user_t *users, char *username)
{
    int i = 0;
    linked_user_t *temp;

    if (!users)
        return (NULL);
    temp = users;
    while (temp) {
        if (temp->ptr && strcmp(temp->ptr->username, username) == 0)
            return (temp->ptr);
        temp = temp->next;
    }
    return (NULL);
}

team_t *find_team_by_name(linked_team_t *teams, char *teamname)
{
    int i = 0;
    linked_team_t *temp;

    if (!teams)
        return (NULL);
    temp = teams;
    while (temp) {
        if (temp->ptr && strcmp(temp->ptr->name, teamname) == 0)
            return (temp->ptr);
        temp = temp->next;
    }
    return (NULL);
}

channel_t *find_channel_by_name(linked_channel_t *channels, char *channelname)
{
    int i = 0;
    linked_channel_t *temp;

    if (!channels)
        return (NULL);
    temp = channels;
    while (temp) {
        if (temp->ptr && strcmp(temp->ptr->name, channelname) == 0)
            return (temp->ptr);
        temp = temp->next;
    }
    return (NULL);
}

thread_t *find_thread_by_name(linked_thread_t *threads, char *threadname)
{
    int i = 0;
    linked_thread_t *temp;

    if (!threads)
        return (NULL);
    temp = threads;
    while (temp) {
        if (temp->ptr && strcmp(temp->ptr->message, threadname) == 0)
            return (temp->ptr);
        temp = temp->next;
    }
    return (NULL);
}

chat_t *find_discussion_by_users(linked_chat_t *chat, user_t *user1,
    user_t *user2)
{
    linked_chat_t *temp;

    if (!chat)
        return (NULL);
    temp = chat;
    while (temp) {
        if ((temp->ptr->user1 == user1 && temp->ptr->user2 == user2)
            || (temp->ptr->user2 == user1 && temp->ptr->user1 == user2))
            return (temp->ptr);
        temp = temp->next;
    }
    return (NULL);
}
