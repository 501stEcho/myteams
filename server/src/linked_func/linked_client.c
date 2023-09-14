/*
** EPITECH PROJECT, 2023
** linkClient
** File description:
** ftp
*/

#include "server.h"

// Ce fichier gères les listes chaînées de client
// Chaque client à son FD, un pointeur sur un user...

linked_client *create_elem(int fd)
{
    linked_client *new = malloc(sizeof(linked_client));

    new->fd = fd;
    new->read_buf = create_buffer(2000);
    new->write_buf = create_buffer(2000);
    new->user = NULL;
    new->quitting = 0;
    new->next = NULL;
    return (new);
}

void push_back(linked_client **head, linked_client *new)
{
    linked_client *temp;

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

void pop_client(linked_client **head, linked_client *client)
{
    linked_client *temp;

    if (!(*head))
        return;
    if (*head == client) {
        *head = (*head)->next;
        destroy_client(client);
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        if (temp->next == client) {
            temp->next = client->next;
            destroy_client(client);
            return;
        }
        temp = temp->next;
    }
}

void destroy_client(linked_client *client)
{
    close(client->fd);
    destroy_buffer(client->read_buf);
    destroy_buffer(client->write_buf);
    free(client);
}

int check_status(linked_client *head, char *username)
{
    linked_client *temp = head;

    while (temp) {
        if (temp->user && strcmp(temp->user->username, username) == 0)
            return (1);
        temp = temp->next;
    }
    return (0);
}
