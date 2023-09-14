/*
** EPITECH PROJECT, 2023
** linked_user
** File description:
** myteams
*/

#include "server.h"

linked_user_t *init_linked_user(user_t *ptr)
{
    linked_user_t *new = malloc(sizeof(linked_user_t));

    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_user(linked_user_t **head, user_t *ptr)
{
    linked_user_t *temp;
    linked_user_t *new = init_linked_user(ptr);

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

void pop_user(linked_user_t **head, user_t *user)
{
    linked_user_t *temp;

    if (!(*head))
        return;
    if ((*head)->ptr == user) {
        *head = (*head)->next;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next->ptr == user) {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
}
