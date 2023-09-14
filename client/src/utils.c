/*
** EPITECH PROJECT, 2022
** my_teams
** File description:
** main
*/

#include "../include/client.h"
#include <string.h>

bool is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < 47 || str[i] > 58)
            return false;
    }
    return true;
}

int nbr_line(char const *str, char c)
{
    int nbr = 0, len = strlen(str);

    for (int i = 0; str[i]; i++) {
        if (str[i] == c)
            nbr++;
    }
    if (len > 3 && str[len - 3] == '\n' && str[len - 2] == '\r' &&
    str[len - 1] == '\n')
        nbr--;
    return (nbr);
}

char *correct_str(char *str)
{
    int len = strlen(str);
    char *new;

    if (str[0] == '\"' && str[len - 1] == '\"') {
        new = &str[1];
        new[len - 2] = '\0';
        return new;
    }
    return str;
}

char ***to_triple_star(char *buff)
{
    int line = nbr_line(buff, '\n');
    char ***tab = malloc_tab(buff, line);

    fill_tab(tab, buff, line);
    if (tab[0])
        do_cmd(tab[0][0], tab, line);
}

void print_minitab(char **tab)
{
    printf("\nMINI TAB\n");
    for (int i = 0; tab[i]; i++) {
        printf("%i:%s\n", i, tab[i]);
    }
    printf("\n");
}
