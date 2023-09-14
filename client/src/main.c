/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** main
*/

#include "../include/client.h"

int main(int ac, char **av)
{
    if (ac == 3) {
        if (ac == 2 && strcmp(av[2], "-help")) {
            printf(USAGE);
            return 0;
        }
        if (is_number(av[2]) == true && (strlen(av[2]) == 4 ||
            strlen(av[2]) == 5)) {
            client_start(ac, av);
            return 0;
        } else {
            printf("Invalid argument\n");
            return 84;
        }
    }
    return 84;
}
