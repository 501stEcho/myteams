/*
** EPITECH PROJECT, 2023
** display_details
** File description:
** teams
*/

#include "server.h"

void detail_team(circular_buf *output, team_t *team)
{
    char *src;
    int n;

    if (!team)
        return;
    n = snprintf(NULL, 0, "\"%s\" \"%s\" \"%s\"\n", team->id,
        team->name, team->description);
    src = creat_str(n);
    sprintf(src, "\"%s\" \"%s\" \"%s\"\n",
        team->id, team->name, team->description);
    write_buffer(output, src, n);
}

void detail_channel(circular_buf *output, channel_t *channel)
{
    char *src;
    int n;

    if (!channel)
        return;
    n = snprintf(NULL, 0, "\"%s\" \"%s\" \"%s\"\n", channel->id,
        channel->name, channel->description);
    src = creat_str(n);
    sprintf(src, "\"%s\" \"%s\" \"%s\"\n",
        channel->id, channel->name, channel->description);
    write_buffer(output, src, n);
}

void detail_thread(circular_buf *output, thread_t *thread)
{
    char *src;
    int n;

    if (!thread)
        return;
    n = snprintf(NULL, 0, "\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"\n",
        thread->id, thread->author_id, thread->timestamp,
        thread->title, thread->message);
    src = creat_str(n);
    sprintf(src, "\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"\n", thread->id,
        thread->author_id, thread->timestamp, thread->title,
        thread->message);
    write_buffer(output, src, n);
}

void detail_reply(circular_buf *output, reply_t *reply)
{
    char *src;
    int n;

    if (!reply)
        return;
    n = snprintf(NULL, 0, "\"%s\" \"%s\" \"%ld\" \"%s\"\n",
        reply->thread_id,
        reply->message, reply->timestamp, reply->message);
    src = creat_str(n);
    sprintf(src, "\"%s\" \"%s\" \"%ld\" \"%s\"\n",
        reply->thread_id, reply->message, reply->timestamp,
        reply->message);
    write_buffer(output, src, n);
}

void detail_messages(circular_buf *output, message_t *conv)
{
    char *src;
    int n;

    if (!conv)
        return;
    n = snprintf(NULL, 0, "\"%s\" \"%ld\" \"%s\"\n",
        conv->sender_id, conv->timestamp,
            conv->message);
    src = creat_str(n);
    sprintf(src, "\"%s\" \"%ld\" \"%s\"\n", conv->sender_id,
        conv->timestamp, conv->message);
    write_buffer(output, src, n);
}
