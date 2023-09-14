/*
** EPITECH PROJECT, 2023
** chat
** File description:
** teams
*/

#include "server.h"

chat_t *init_chat(user_t *user1, user_t *user2)
{
    chat_t *new = malloc(sizeof(chat_t));

    new->user1 = user1;
    new->user2 = user2;
    new->conv = NULL;
    return (new);
}

void destroy_chat(chat_t *command)
{
    free(command);
}

chat_t *create_discussion(server_t *server, user_t *user1, user_t *user2)
{
    chat_t *chat = init_chat(user1, user2);

    push_chat(&server->chats, chat);
    return (chat);
}
