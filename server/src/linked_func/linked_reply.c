/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

linked_reply_t *init_linked_reply(reply_t *ptr)
{
    linked_reply_t *new = malloc(sizeof(linked_reply_t));

    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_reply(linked_reply_t **head, reply_t *ptr)
{
    linked_reply_t *temp;
    linked_reply_t *new;

    if (!ptr)
        return;
    new = init_linked_reply(ptr);
    if (!(*head)) {
        *head = new;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void pop_reply(linked_reply_t **head, reply_t *reply)
{
    linked_reply_t *temp;

    if (!(*head))
        return;
    if ((*head)->ptr == reply) {
        *head = (*head)->next;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next->ptr == reply) {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
}
