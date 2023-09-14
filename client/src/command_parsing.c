/*
** EPITECH PROJECT, 2023
** command_parsing
** File description:
** teams
*/

#include "../include/client.h"

char *getcmd(void)
{
    size_t size = 4096;
    char *command = malloc(sizeof(char) * size);
    getline(&command, &size, stdin);
    return command;
}

char *good_str(char *str, char *cat, int nb)
{
    int len = strlen(str), len_cat = strlen(cat);
    char *new_str = malloc(sizeof(char) * (len + len_cat + 1));

    str[len - nb] = '\0';
    strcpy(new_str, str);
    strcat(new_str, cat);
    return new_str;
}
