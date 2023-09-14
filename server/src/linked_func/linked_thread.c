/*
** EPITECH PROJECT, 2023
** linked_thread
** File description:
** teams
*/

#include "server.h"

linked_thread_t *init_linked_thread(thread_t *ptr)
{
    linked_thread_t *new = malloc(sizeof(linked_thread_t));

    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_thread(linked_thread_t **head, thread_t *ptr)
{
    linked_thread_t *temp;
    linked_thread_t *new = init_linked_thread(ptr);

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

void pop_thread(linked_thread_t **head, thread_t *team)
{
    linked_thread_t *temp;

    if (!(*head))
        return;
    if ((*head)->ptr == team) {
        *head = (*head)->next;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next->ptr == team) {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
}
