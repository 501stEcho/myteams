/*
** EPITECH PROJECT, 2023
** save_conv
** File description:
** teams
*/

#include "server.h"

void save_message(FILE *fd, message_t *conv)
{
    fprintf(fd, "{\n");
    fprintf(fd, "%s\n%s\n%ld\n", conv->sender_id, conv->message,
        conv->timestamp);
    fprintf(fd, "}\n");
}

void save_conv(FILE *fd, chat_t *conv)
{
    fprintf(fd, "{\n");
    fprintf(fd, "%s\n%s\n", conv->user1->id, conv->user2->id);
    for (linked_message_t *temp = conv->conv; temp; temp = temp->next) {
        save_message(fd, temp->ptr);
    }
    fprintf(fd, "}\n");
}
