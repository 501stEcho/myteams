/*
** EPITECH PROJECT, 2023
** split
** File description:
** ftp
*/

#include "server.h"

int valid_command_format(char *str)
{
    int i = 0;
    int quote = 0;

    for (;str[i] && str[i] == ' ';i++);
    if (!(str[i] && str[i] == '/'))
        return (0);
    for (;str[i] && str[i] != ' ';i++);
    for (;str[i];i++) {
        if (str[i] == '"' && quote && (str[i + 1] && str[i + 1] != ' ')) {
            return (0);
        }
        if (str[i] == ' ' && str[i + 1] != ' ' && str[i + 1] != '"' && !quote) {
            return (0);
        }
        if (str[i] == '"')
            quote = !quote;
    }
    if (quote)
        return (0);
    return (1);
}

int get_arg_nb(char *str)
{
    int i = 0;
    int quote = 0;
    int args = 0;

    for (;str[i] && str[i] == ' ';i++);
    if (str[i] && str[i] == '/') {
        args++;
        for (;str[i] && str[i] != ' ';i++);
    }
    while (str[i]) {
        if (str[i] == '"' && !quote)
            args++;
        quote = (str[i] == '"' ? !quote : quote);
        i++;
    }
    return (args);
}

char **split_command(char *str)
{
    int args = get_arg_nb(str);
    char **res = creat_tab(args);
    int j = 0;
    int i = 0;
    int quote = 0;
    int checkp = 0;
    if (!str || args == 0)
        return (res);
    for (;str[i] && str[i] == ' ';i++);
    if (str[i] && str[i] == '/') {
        for (checkp = i + 1;str[i] && str[i] != ' ';i++);
        res[j++] = strndup(&str[checkp], i - checkp);
    }
    for (;str[i];quote = (str[i] == '"' ? !quote : quote), i++) {
        if (str[i] == '"' && !quote)
            checkp = i + 1;
        if (str[i] == '"' && quote)
            res[j++] = strndup(&str[checkp], i - checkp);
    }
    return (res);
}
