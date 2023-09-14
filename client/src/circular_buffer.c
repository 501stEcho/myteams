/*
** EPITECH PROJECT, 2023
** circular_buffer
** File description:
** ftp
*/

#include "../include/client.h"

circular_buf *create_buffer(unsigned int length)
{
    circular_buf *buffer = malloc(sizeof(circular_buf));

    buffer->buf = malloc((length + 1) * sizeof(char *));
    buffer->buf[length] = 0;
    buffer->length = length;
    buffer->rd = 0;
    buffer->wt = 0;
    return buffer;
}

char *circular_copy(circular_buf *buf, int n)
{
    char *res = malloc((n + 1) * sizeof(char));
    int j = buf->rd;

    res[n] = '\0';
    for (int i = 0; i < n; i++) {
        res[i] = buf->buf[j % buf->length];
        j++;
    }
    return (res);
}

void write_buffer(circular_buf *buf, char *src, int len)
{
    int i = 0;

    if (len < 0)
        len = strlen(src);
    while (i < len) {
        buf->buf[buf->wt % buf->length] = src[i];
        i++;
        buf->wt++;
    }
}

char *read_buffer(circular_buf *buf)
{
    char *res;
    int i = 0;

    if (buf->rd == buf->wt) {
        return (NULL);
    }
    res = malloc((buf->wt - buf->rd + 1) * sizeof(char));
    res[buf->wt - buf->rd] = 0;

    while (buf->rd < buf->wt) {
        res[i] = buf->buf[buf->rd % buf->length];
        buf->rd++;
        i++;
    }
    return (res);
}

void destroy_buffer(circular_buf *buf)
{
    free(buf->buf);
    free(buf);
}
