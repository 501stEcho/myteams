/*
** EPITECH PROJECT, 2023
** format
** File description:
** server
*/

#include "server.h"

char *format_one_string(char *signal, char *uuid)
{
    char *src;
    int n;

    n = snprintf(NULL, 0, "%s\"%s\"\r\n", signal, uuid);
    src = creat_str(n);
    sprintf(src, "%s\"%s\"\r\n", signal, uuid);
    return (src);
}

char *format_two_string(char *signal, char *str1, char *str2)
{
    char *src;
    int n;

    n = snprintf(NULL, 0, "%s\"%s\" \"%s\"\r\n", signal, str1, str2);
    src = creat_str(n);
    sprintf(src, "%s\"%s\" \"%s\"\r\n", signal, str1, str2);
    return (src);
}

char *format_three_string(char *signal, char *str1, char *str2, char *str3)
{
    char *src;
    int n;

    n = snprintf(NULL, 0, "%s\"%s\" \"%s\" \"%s\"\r\n", signal, str1, str2,
        str3);
    src = creat_str(n);
    sprintf(src, "%s\"%s\" \"%s\" \"%s\"\r\n", signal, str1, str2, str3);
    return (src);
}

char *describe_thread(char *signal, thread_t *thread)
{
    char *src;
    int n;
    char const *thread_uuid;
    char const *user_uuid;
    time_t thread_timestamp;
    char const *thread_title;
    char const *thread_body;

    n = snprintf(NULL, 0, "%s\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"\r\n", signal,
        thread->id, thread->author_id, thread->timestamp,
        thread->title, thread->message);
    src = creat_str(n);
    sprintf(src, "%s\"%s\" \"%s\" \"%ld\" \"%s\" \"%s\"\r\n", signal,
        thread->id, thread->author_id, thread->timestamp,
        thread->title, thread->message);
    return (src);
}

char *describe_reply(char *signal, reply_t *reply)
{
    char *src;
    int n;
    char const *thread_uuid;
    char const *user_uuid;
    time_t thread_timestamp;
    char const *thread_title;
    char const *thread_body;

    n = snprintf(NULL, 0, "%s\"%s\" \"%s\" \"%s\" \"%s\"\r\n", signal,
        reply->team_id, reply->thread_id, reply->author_id, reply->message);
    src = creat_str(n);
    sprintf(src, "%s\"%s\" \"%s\" \"%s\" \"%s\"\r\n", signal,
        reply->team_id, reply->thread_id, reply->author_id, reply->message);
    return (src);
}
