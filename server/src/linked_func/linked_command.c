/*
** EPITECH PROJECT, 2023
** linked_command
** File description:
** myteams
*/

#include "server.h"

command_t *init_command(char *name, void (*ptr)(server_t *,
    linked_client *, char **))
{
    command_t *new = malloc(sizeof(command_t));

    new->name = strdup(name);
    new->ptr = ptr;
    new->next = NULL;
    return (new);
}

void push_command(command_t **head, char *name, void (*ptr)(server_t *,
    linked_client *, char **))
{
    command_t *temp;
    command_t *new = init_command(name, ptr);

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

void pop_command(command_t **head, command_t *command)
{
    command_t *temp;

    if (!(*head))
        return;
    if (*head == command) {
        *head = (*head)->next;
        destroy_command(command);
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next == command) {
            temp->next = command->next;
            destroy_command(command);
            return;
        }
        temp = temp->next;
    }
}

void destroy_command(command_t *command)
{
    free(command->name);
    free(command);
}
