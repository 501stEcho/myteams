/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

thread_t *init_thread(char *title, char *msgbody, char *author_id)
{
    thread_t *new = malloc(sizeof(thread_t));
    uuid_t uid;

    new->id = malloc(37 * sizeof(char));
    uuid_generate(uid);
    uuid_unparse_lower(uid, new->id);
    new->title = strdup(title);
    new->message = strdup(msgbody);
    new->author_id = strdup(author_id);
    new->timestamp = time(NULL);
    return (new);
}

void destroy_thread(thread_t *thread)
{
    free(thread->id);
    free(thread->title);
    free(thread->author_id);
    free(thread->message);
    free(thread);
}
