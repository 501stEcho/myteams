/*
** EPITECH PROJECT, 2023
** load
** File description:
** teams
*/

#include "server.h"

void load_reply(FILE *fd, linked_reply_t **replies)
{
    char *line = NULL;
    size_t len = 0;
    int step = 0;
    reply_t *reply = malloc(sizeof(reply_t));

    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "}") == 0)
            break;
        if (!(strcmp(line, "{") == 0 || strcmp(line, "}") == 0))
            fill_reply(line, reply, &step);
    }
    push_reply(replies, reply);
}

void load_thread(FILE *fd, linked_thread_t **threads)
{
    char *line = NULL;
    size_t len = 0;
    int step = 0;
    thread_t *thread = malloc(sizeof(thread_t));

    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            load_reply(fd, &thread->replies);
        if (strcmp(line, "}") == 0)
            break;
        if (!(strcmp(line, "{") == 0 || strcmp(line, "}") == 0))
            fill_thread(line, thread, &step);
    }
    push_thread(threads, thread);
}

void load_channel(FILE *fd, linked_channel_t **channels)
{
    char *line = NULL;
    size_t len = 0;
    int step = 0;
    channel_t *channel = malloc(sizeof(channel_t));

    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            load_thread(fd, &channel->threads);
        if (strcmp(line, "}") == 0)
            break;
        if (!(strcmp(line, "{") == 0 || strcmp(line, "}") == 0))
            fill_channel(line, channel, &step);
    }
    push_channel(channels, channel);
}

void load_team(FILE *fd, linked_team_t **teams)
{
    char *line = NULL;
    size_t len = 0;
    int step = 0;
    team_t *team = malloc(sizeof(team_t));

    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            load_channel(fd, &team->channels);
        if (strcmp(line, "}") == 0)
            break;
        if (!(strcmp(line, "{") == 0 || strcmp(line, "}") == 0))
            fill_team(line, team, &step);
    }
    push_team(teams, team);
}

void load_teams(char *path, linked_team_t **teams)
{
    FILE *fd;
    char *line = NULL;
    size_t len = 0;

    fd = fopen(path, "r");
    if (!fd) {
        printf("Unable to load teams\n");
        return;
    }
    while (getline(&line, &len, fd) > 0) {
        if (line[strlen(line) - 1] == '\n')
            line[strlen(line) - 1] = 0;
        if (strcmp(line, "{") == 0)
            load_team(fd, teams);
    }
}
