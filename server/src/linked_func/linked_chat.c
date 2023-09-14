/*
** EPITECH PROJECT, 2023
** linked_chat
** File description:
** my_teams
*/

#include "server.h"

linked_chat_t *init_linked_chat(chat_t *ptr)
{
    linked_chat_t *new = malloc(sizeof(linked_chat_t));

    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_chat(linked_chat_t **head, chat_t *ptr)
{
    linked_chat_t *temp;
    linked_chat_t *new = init_linked_chat(ptr);

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

void pop_chat(linked_chat_t **head, chat_t *chat)
{
    linked_chat_t *temp;

    if (!(*head))
        return;
    if ((*head)->ptr == chat) {
        *head = (*head)->next;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next->ptr == chat) {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
}
