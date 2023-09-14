/*
** EPITECH PROJECT, 2023
** Error handling
** File description:
** ftp
*/

#include "server.h"

// Error handling

int check_valid_arg(int argc, char **argv)
{
    if (argc < 2)
        exit(84);
    check_flags(argc, argv);
    if (is_nbr(argv[1]) == 0)
        exit(84);
}

int handle_args(int argc, char **argv, server_t **server)
{
    check_valid_arg(argc, argv);
    *server = malloc(sizeof(server_t));
    (*server)->port = getshort(argv[1]);
    (*server)->head = NULL;
    (*server)->users = malloc(sizeof(user_t *));
    (*server)->users = NULL;
    (*server)->commands = malloc(sizeof(command_t *));
    (*(*server)->commands) = NULL;
    (*server)->teams = malloc(sizeof(team_t *));
    (*server)->teams = NULL;
    (*server)->chats = NULL;
    init_commands(*server);
}
