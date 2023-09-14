/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

linked_channel_t *init_linked_channel(channel_t *ptr)
{
    linked_channel_t *new = malloc(sizeof(linked_channel_t));

    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_channel(linked_channel_t **head, channel_t *ptr)
{
    linked_channel_t *temp;
    linked_channel_t *new = init_linked_channel(ptr);

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

void pop_channel(linked_channel_t **head, channel_t *chan)
{
    linked_channel_t *temp;

    if (!(*head))
        return;
    if ((*head)->ptr == chan) {
        *head = (*head)->next;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next->ptr == chan) {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
}
