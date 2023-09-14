/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

linked_message_t *init_linked_message(message_t *ptr)
{
    linked_message_t *new = malloc(sizeof(linked_message_t));

    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_message(linked_message_t **head, message_t *ptr)
{
    linked_message_t *temp;
    linked_message_t *new = init_linked_message(ptr);

    if (!(*head)) {
        *head = new;
        return;
    }
    temp = *head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new;
}

void pop_message(linked_message_t **head, message_t *reply)
{
    linked_message_t *temp;

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
