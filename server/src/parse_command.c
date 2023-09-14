/*
** EPITECH PROJECT, 2023
** parse_command
** File description:
** myteams
*/

#include "server.h"

// Parsing des commandes reçues lors de la lectures des buffer
// circulaires des client.

int get_command_nb(circular_buf *buf)
{
    int count = 0;

    for (int i = buf->rd; i + 1 < buf->wt; i++) {
        if (buf->buf[i % buf->length] == '\r' &&
            buf->buf[(i + 1) % buf->length] == '\n') {
            count++;
            i++;
        }
    }
    return (count);
}

char **get_command(circular_buf *buf)
{
    char **result;
    int j = 0;
    int last = buf->rd;
    int count = get_command_nb(buf);

    if (count <= 0)
        return (NULL);
    result = creat_tab(count);
    for (int i = buf->rd; j < count && i + 1 < buf->wt; i++) {
        if (buf->buf[i % buf->length] == '\r' &&
            buf->buf[(i + 1) % buf->length] == '\n') {
            result[j] = circular_copy(buf, i - last + 2);
            last = i + 2;
            buf->rd = i + 2;
            i++;
        }
    }
    return (result);
}
