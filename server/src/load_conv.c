/*
** EPITECH PROJECT, 2023
** load_conv
** File description:
** teams
*/

#include "server.h"

void fill_message(char *line, message_t *message, int *step)
{
    switch (*step) {
        case (0):
            fill_field(&(message->sender_id), line, step);
            break;
        case (1):
            fill_field(&(message->message), line, step);
            break;
        case (2):
            message->timestamp = long_to_str(line);
            (*step)++;
            break;
        default:
            break;
    }
}

void fill_conv(char *line, chat_t *chat, int *step, linked_user_t *users)
{
    user_t *target;

    target = find_user_by_id(users, line);
    switch (*step) {
        case (0):
            chat->user1 = target;
            (*step)++;
            break;
        case (1):
            chat->user2 = target;
            (*step)++;
            break;
        default:
            break;
    }
}

void load_message(FILE *fd, linked_message_t **messages)
{
    char *line = NULL;
    size_t len = 0;
    int step = 0;
    message_t *message = malloc(sizeof(message_t));

    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "}") == 0)
            break;
        if (!(strcmp(line, "{") == 0 || strcmp(line, "}") == 0))
            fill_message(line, message, &step);
    }
    push_message(messages, message);
}

void load_conv(FILE *fd, linked_chat_t **chats, linked_user_t *users)
{
    char *line = NULL;
    size_t len = 0;
    int step = 0;
    chat_t *chat = malloc(sizeof(chat_t));

    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            load_message(fd, &chat->conv);
        if (strcmp(line, "}") == 0)
            break;
        if (!(strcmp(line, "{") == 0 || strcmp(line, "}") == 0))
            fill_conv(line, chat, &step, users);
    }
    if (chat->user1 && chat->user2)
        push_chat(chats, chat);
}

void load_convs(char *path, linked_chat_t **chats, linked_user_t *users)
{
    FILE *fd;
    char *line = NULL;
    size_t len = 0;

    fd = fopen(path, "r");
    if (!fd) {
        printf("Unable to load teams\n");
        return;
    }
    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            load_conv(fd, chats, users);
    }
}
