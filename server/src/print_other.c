/*
** EPITECH PROJECT, 2023
** print
** File description:
** teams
*/

#include "server.h"

void detail_user(circular_buf *output, user_t *user)
{
    char *src;
    int n;
    int online = 0;

    if (!user)
        return;
    online = (user->tracker > 0 ? 1 : 0);
    n = snprintf(NULL, 0, "\"%s\" \"%s\" \"%d\"\n", user->id,
        user->username, online);
    src = creat_str(n);
    sprintf(src, "\"%s\" \"%s\" \"%d\"\n",
        user->id, user->username, online);
    write_buffer(output, src, n);
}

void print_users(circular_buf *output, linked_user_t *users)
{
    for (linked_user_t *temp = users; temp; temp = temp->next)
        detail_user(output, temp->ptr);
}
