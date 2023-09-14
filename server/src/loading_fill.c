/*
** EPITECH PROJECT, 2023
** loading_fill
** File description:
** teams
*/

#include "server.h"

void fill_field(char **dest, char *src, int *step)
{
    *dest = strdup(src);
    (*step)++;
}

void fill_reply(char *line, reply_t *reply, int *step)
{
    switch (*step) {
        case (0) :
            fill_field(&(reply->team_id), line, step);
            break;
        case (1) :
            fill_field(&(reply->message), line, step);
            break;
        case (2) :
            fill_field(&(reply->thread_id), line, step);
            break;
        case (3) :
            fill_field(&(reply->author_id), line, step);
            break;
        case (4) :
            reply->timestamp = long_to_str(line);
            (*step)++;
            break;
        default:
            break;
    }
}

void fill_thread(char *line, thread_t *thread, int *step)
{
    switch (*step) {
        case (0) :
            fill_field(&(thread->id), line, step);
            break;
        case (1) :
            fill_field(&(thread->author_id), line, step);
            break;
        case (2) :
            fill_field(&(thread->title), line, step);
            break;
        case (3) :
            fill_field(&(thread->message), line, step);
            break;
        case (4) :
            thread->timestamp = long_to_str(line);
            (*step)++;
            break;
        default:
            break;
    }
}

void fill_channel(char *line, channel_t *channel, int *step)
{
    switch (*step) {
        case (0) :
            channel->id = strdup(line);
            (*step)++;
            break;
        case (1) :
            channel->name = strdup(line);
            (*step)++;
            break;
        case (2) :
            channel->description = strdup(line);
            (*step)++;
            break;
        default:
            break;
    }
}

void fill_team(char *line, team_t *team, int *step)
{
    switch (*step) {
        case (0) :
            team->id = strdup(line);
            (*step)++;
            break;
        case (1) :
            team->name = strdup(line);
            (*step)++;
            break;
        case (2) :
            team->description = strdup(line);
            (*step)++;
            break;
        default:
            break;
    }
}
