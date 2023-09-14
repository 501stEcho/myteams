/*
** EPITECH PROJECT, 2023
** save
** File description:
** teams
*/

#include "server.h"

void save_convs(char *path, linked_chat_t *convs)
{
    FILE *fd;

    fd = fopen(path, "w");

    if (!fd) {
        printf("Cannot save convs\n");
        return;
    }
    for (linked_chat_t *temp = convs; temp; temp = temp->next) {
        save_conv(fd, temp->ptr);
    }
    fclose(fd);
}

void save_teams(char *path, linked_team_t *teams)
{
    FILE *fd;

    fd = fopen(path, "w");

    if (!fd) {
        printf("Cannot save teams\n");
        return;
    }
    for (linked_team_t *temp = teams; temp; temp = temp->next) {
        save_team(fd, temp->ptr);
    }
    fclose(fd);
}

void save_users(char *path, linked_user_t *users)
{
    FILE *fd;

    fd = fopen(path, "w");

    if (!fd) {
        printf("Cannot save teams\n");
        return;
    }
    for (linked_user_t *temp = users; temp; temp = temp->next) {
        save_user(fd, temp->ptr);
    }
    fclose(fd);
}

void saveguard_server(server_t *server)
{
    save_users("./save/users.log", server->users);
    save_teams("./save/teams.log", server->teams);
    save_convs("./save/convs.log", server->chats);
}
