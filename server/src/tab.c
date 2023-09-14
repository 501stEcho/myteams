/*
** EPITECH PROJECT, 2023
** tab
** File description:
** ftp
*/

#include "server.h"

char **creat_tab(int len)
{
    char **tab = malloc((len + 1) * sizeof(char *));

    tab[len] = 0;
    return (tab);
}

void display_tab(char **tab)
{
    int i = 0;
    char c = '\n';

    while (tab[i]) {
        write(1, tab[i], strlen(tab[i]));
        write(1, &c, 1);
        i++;
    }
}

int tab_len(char **tab)
{
    int i = 0;

    while (tab[i]) {
        i++;
    }
    return (i);
}

void free_tab(char **tab)
{
    int i = 0;

    if (!tab)
        return;
    while (tab[i]) {
        free(tab[i]);
    }
    free(tab);
}
