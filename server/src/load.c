/*
** EPITECH PROJECT, 2023
** load
** File description:
** teams
*/

#include "server.h"

void load_backup(server_t *server)
{
    load_teams("./save/teams.log", &server->teams);
    load_users("./save/users.log", &server->users, server->teams);
    load_convs("./save/convs.log", &server->chats, server->users);
}
