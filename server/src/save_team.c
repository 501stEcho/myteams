/*
** EPITECH PROJECT, 2023
** save
** File description:
** teams
*/

#include "server.h"

void save_team(FILE *fd, team_t *team)
{
    fprintf(fd, "{\n");
    fprintf(fd, "%s\n%s\n%s\n", team->id, team->name, team->description);
    for (linked_channel_t *temp = team->channels; temp; temp = temp->next) {
        save_channel(fd, temp->ptr);
    }
    fprintf(fd, "}\n");
}

void save_channel(FILE *fd, channel_t *channel)
{
    fprintf(fd, "{\n");
    fprintf(fd, "%s\n%s\n%s\n", channel->id, channel->name,
        channel->description);
    for (linked_thread_t *temp = channel->threads; temp; temp = temp->next) {
        save_thread(fd, temp->ptr);
    }
    fprintf(fd, "}\n");
}

void save_thread(FILE *fd, thread_t *thread)
{
    fprintf(fd, "{\n");
    fprintf(fd, "%s\n%s\n%s\n%s\n%ld\n", thread->id, thread->author_id,
        thread->title, thread->message, thread->timestamp);
    for (linked_reply_t *temp = thread->replies; temp; temp = temp->next) {
        save_reply(fd, temp->ptr);
    }
    fprintf(fd, "}\n");
}

void save_reply(FILE *fd, reply_t *reply)
{
    fprintf(fd, "{\n");
    fprintf(fd, "%s\n%s\n%s\n%s\n%ld\n", reply->team_id, reply->message,
        reply->thread_id, reply->author_id, reply->timestamp);
    fprintf(fd, "}\n");
}
