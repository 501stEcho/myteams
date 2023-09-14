/*
** EPITECH PROJECT, 2023
** load
** File description:
** teams
*/

#include "server.h"

void fill_user2(char *line, user_t *user, int *step, linked_team_t *teams)
{
    switch (*step) {
        case (3) :
            user->current_team = (strcmp(line, "NULL") == 0 ? NULL :
                find_team_by_id(teams, line));
            (*step)++;
            break;
        case (4) :
            user->current_channel = (strcmp(line, "NULL") == 0 ? NULL :
                find_channel_by_id(user->current_team->channels, line));
            (*step)++;
            break;
        case (5) :
            user->current_thread = (strcmp(line, "NULL") == 0 ? NULL :
                find_thread_by_id(user->current_channel->threads, line));
            (*step)++;
            break;
        default:
            break;
    }
}

void fill_user(char *line, user_t *user, int *step, linked_team_t *teams)
{
    team_t *target;

    if (*step > 2)
        return (fill_user2(line, user, step, teams));
    switch (*step) {
        case (0) :
            user->id = strdup(line);
            (*step)++;
            break;
        case (1) :
            user->username = strdup(line);
            (*step)++;
            break;
        case (2) :
            target = find_team_by_id(teams, line);
            push_team(&user->subscribed, target);
            break;
        default:
            break;
    }
}

void load_user(FILE *fd, linked_user_t **users, linked_team_t *teams)
{
    char *line = NULL;
    int depth = 0;
    int step = 0;
    user_t *user = malloc(sizeof(user_t));
    for (size_t len = 0; getline(&line, &len, fd) > 0;) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            depth++;
        if (strcmp(line, "}") == 0) {
            step++;
            depth--;
        }
        if (depth < 0)
            break;
        if (!(strcmp(line, "{") == 0 || strcmp(line, "}") == 0))
            fill_user(line, user, &step, teams);
    }
    push_user(users, user);
    server_event_user_loaded(user->id, user->username);
}

void load_users(char *path, linked_user_t **users, linked_team_t *teams)
{
    FILE *fd;
    char *line = NULL;
    size_t len = 0;

    fd = fopen(path, "r");
    if (!fd) {
        printf("Unable to load users\n");
        return;
    }
    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            load_user(fd, users, teams);
    }
}
