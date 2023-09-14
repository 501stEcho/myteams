/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** main
*/

#include "../include/client.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int list_function(int code, char ***buf, int idx)
{
    if (code == 302)
        client_print_teams(buf[idx][0], buf[idx][1], buf[idx][2]);
    if (code == 304)
        client_team_print_channels(buf[idx][0], buf[idx][1], buf[idx][2]);
    if (code == 306)
        client_channel_print_threads(buf[idx][0], buf[idx][1],
        atoi(buf[idx][3]), buf[idx][4], buf[idx][5]);
    if (code == 308)
        client_thread_print_replies(buf[idx][0], buf[idx][1], \
        atoi(buf[idx][3]), buf[idx][4]);
    return 0;
}

int create_function(int code, char ***buf, int idx)
{
    if (code == 120)
        client_print_unsubscribed(buf[idx][0], buf[idx][1]);
    if (code == 202)
        client_event_team_created(buf[idx][0], buf[idx][1], buf[idx][2]);
    if (code == 204)
        client_event_channel_created(buf[idx][0], buf[idx][1], buf[idx][2]);
    if (code == 206)
        client_event_thread_created(buf[idx][0], buf[idx][1],
        atoi(buf[idx][2]), buf[idx][3], buf[idx][4]);
    if (code == 208)
        client_event_thread_reply_received(buf[idx][0], buf[idx][1], \
        buf[idx][2], buf[idx][3]);
    return 0;
}

int feature_function(int code, char ***buf, int idx)
{
    if (code == 102)
        client_event_logged_in(buf[idx][0], buf[idx][1]);
    if (code == 104)
        client_event_logged_out(buf[idx][0], buf[idx][1]);
    if (code == 106)
        client_print_users(buf[idx][0], buf[idx][1], atoi(buf[idx][2]));
    if (code == 108)
        client_print_user(buf[idx][0], buf[idx][1], atoi(buf[idx][2]));
    if (code == 110)
        client_event_private_message_received(buf[idx][0], buf[idx][1]);
    if (code == 112)
        client_private_message_print_messages(buf[idx][0], atoi(buf[idx][1]),
            buf[idx][2]);
    if (code == 114)
        client_print_subscribed(buf[idx][0], buf[idx][1]);
    if (code == 116)
        client_print_teams(buf[idx][0], buf[idx][1], buf[idx][2]);
    if (code == 118)
        client_print_users(buf[idx][0], buf[idx][1], atoi(buf[idx][2]));
    return 0;
}

int info_function(int code, char ***buf, int idx)
{
    if (code == 402)
        client_print_user(buf[idx][0], buf[idx][1], atoi(buf[idx][2]));
    if (code == 404)
        client_print_team(buf[idx][0], buf[idx][1], buf[idx][2]);
    if (code == 406)
        client_print_channel(buf[idx][0], buf[idx][1], buf[idx][2]);
    if (code == 408)
        client_print_thread(buf[idx][0], buf[idx][1], atoi(buf[idx][2]), \
        buf[idx][3], buf[idx][4]);
    return 0;
}

int error_function(int code, char ***buf, int idx)
{
    if (code == 501)
        client_error_unknown_team(buf[idx][0]);
    if (code == 503)
        client_error_unknown_channel(buf[idx][0]);
    if (code == 505)
        client_error_unknown_thread(buf[idx][0]);
    if (code == 507)
        client_error_unknown_user(buf[idx][0]);
    if (code == 509)
        client_error_unauthorized();
    if (code == 511)
        client_error_already_exist();
    return 0;
}
