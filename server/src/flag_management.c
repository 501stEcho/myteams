/*
** EPITECH PROJECT, 2023
** flag management
** File description:
** ftp
*/

#include "server.h"

// Gestion des flags

void print_help(void)
{
    printf("USAGE: ./myteams_server port\n");
    printf("\n       port is the port number on which the ");
    printf("server socket listens\n");
    exit(0);
}

int check_flags(int argc, char **argv)
{
    if (argc == 2) {
        if (strcmp(argv[1], "-help") == 0) {
            print_help();
        }
    }
    if (argc > 2)
        exit(84);
}
