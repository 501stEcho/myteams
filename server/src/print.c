/*
** EPITECH PROJECT, 2023
** print
** File description:
** teams
*/

#include "server.h"

void print_teams(circular_buf *output, linked_team_t *teams)
{
    char *src;
    int n;

    for (linked_team_t *temp = teams; temp; temp = temp->next) {
        detail_team(output, temp->ptr);
    }
}

void print_channel(circular_buf *output, linked_channel_t *channels)
{
    char *src;
    int n;

    for (linked_channel_t *temp = channels; temp; temp = temp->next) {
        detail_channel(output, temp->ptr);
    }
}

void print_thread(circular_buf *output, linked_thread_t *threads)
{
    char *src;
    int n;

    for (linked_thread_t *temp = threads; temp;
        temp = temp->next) {
        detail_thread(output, temp->ptr);
    }
}

void print_reply(circular_buf *output, linked_reply_t *replies)
{
    char *src;
    int n;

    for (linked_reply_t *temp = replies; temp; temp = temp->next) {
        detail_reply(output, temp->ptr);
    }
}

void print_messages(circular_buf *output, linked_message_t *conv)
{
    char *src;
    int n;

    for (linked_message_t *temp = conv; temp; temp = temp->next) {
        detail_messages(output, temp->ptr);
    }
}
