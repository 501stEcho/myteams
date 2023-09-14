/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

message_t *init_message(char *sender_id, char *msgbody)
{
    message_t *new = malloc(sizeof(message_t));
    uuid_t uid;

    new->sender_id = sender_id;
    new->message = strdup(msgbody);
    new->timestamp = time(NULL);
    return (new);
}

void destroy_message(message_t *reply)
{
    free(reply->sender_id);
    free(reply->message);
    free(reply);
}
