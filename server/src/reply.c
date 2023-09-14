/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

reply_t *init_reply(char *author_id, char *msgbody, char *thread_id,
    char *team_id)
{
    reply_t *new = malloc(sizeof(reply_t));
    uuid_t uid;

    new->author_id = strdup(author_id);
    new->thread_id = strdup(thread_id);
    new->message = strdup(msgbody);
    new->timestamp = time(NULL);
    new->team_id = strdup(team_id);
    return (new);
}

void destroy_reply(reply_t *reply)
{
    free(reply->author_id);
    free(reply->thread_id);
    free(reply->message);
    free(reply->team_id);
    free(reply);
}
