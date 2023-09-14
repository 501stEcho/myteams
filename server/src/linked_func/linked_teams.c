/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

linked_team_t *init_linked_team(team_t *ptr)
{
    linked_team_t *new = malloc(sizeof(linked_team_t));

    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_team(linked_team_t **head, team_t *ptr)
{
    linked_team_t *temp;
    linked_team_t *new;

    if (!ptr)
        return;
    new = init_linked_team(ptr);
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

void pop_team(linked_team_t **head, team_t *team)
{
    linked_team_t *temp;

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
