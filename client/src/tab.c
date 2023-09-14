/*
** EPITECH PROJECT, 2023
** tab
** File description:
** ftp
*/

#include "../include/client.h"

void print_tab(char ***tab)
{
    for (int x = 0; tab[x]; x++) {
        printf("%i:", x);
        for (int y = 0; tab[x][y]; y++) {
            printf(" |%s|", tab[x][y]);
        }
        printf("\n");
    }
}

char ***malloc_tab(char *buff, int line)
{
    char ***tab = malloc(sizeof(char **) * (line + 1));

    for (int i = 0, j; i < line; i++) {
        tab[i] = NULL;
        tab[i] = malloc(sizeof(char *) * 10);
        for (j = 0; j < 10; j++)
            tab[i][j] = NULL;
    }
    tab[line] = NULL;
    return tab;
}

char *with_quotes(char *str, char *word, int *head)
{
    int idx_quote = 0, i = 0;

    for (idx_quote++; str[idx_quote] != '\"'; idx_quote++);
    for (i = 1; i < idx_quote; i++)
        word[i - 1] = str[i];
    word[i - 1] = '\0';
    if (str[idx_quote + 1] == ' ')
        *head += idx_quote + 2;
    else
        *head = -1;
    return word;
}

char *next_word(char *src, int *head)
{
    int idx_quote = 0, i = 0;
    char *word = malloc(sizeof(char) * 2001), *str;

    str = strdup(&src[*head]);
    if (str[0] == '\"')
        return with_quotes(str, word, head);
    else {
        for (i = 0; str[i] != '\0' && str[i] != ' '; i++)
            word[i] = str[i];
        word[i] = '\0';
    }
    if (str[i] != '\0')
        *head += i + 1;
    else
        *head = -1;
    return word;
}

void fill_tab(char ***tab, char *buff, int nbr_l)
{
    int head = 0;
    char *line, *word;
    char **mini_tab = malloc(sizeof(char *) * (nbr_l + 1));

    line = strtok(buff, "\n");
    for (int i = 0; i < nbr_l; i++, line = strtok(NULL, "\n")) {
        mini_tab[i] = NULL;
        line = good_str(line, "\0", 0);
        mini_tab[i] = line;
    }
    mini_tab[nbr_l] = NULL;
    for (int i = 0, j = 0, x = 0; mini_tab[x]; i++, x++, head = 0) {
        for (j = 0; head != -1; j++) {
            word = next_word(mini_tab[x], &head);
            tab[i][j] = strdup(word);
        }
    }
}
