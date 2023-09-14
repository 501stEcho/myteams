/*
** EPITECH PROJECT, 2023
** tools
** File description:
** ftp
*/

#include "server.h"

// Petites fonctions qui servent régulièrement

int write_message(int client_fd, char *msg)
{
    if (!msg)
        return (0);
    if (write(client_fd, msg, strlen(msg)) < 0) {
        perror("Write failed");
        return (84);
    }
}

int emit_error(server_t *server, char *msg)
{
    perror(msg);
    free(server);
    return (-1);
}

int is_num(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int is_nbr(char *str)
{
    int i = 0;
    int len = strlen(str);

    while (str[i]) {
        if (!(is_num(str[0]) == 1))
            return (0);
        i++;
    }
    return (1);
}

uint16_t getshort(char *str)
{
    uint16_t res = 0;
    int sign = 1;

    if (str[0] && str[0] == '-')
        sign *= -1;
    for (int i = 0; str[i] >= '0' && str[i] <= '9'; i++) {
        res *= 10;
        res += str[i] - 48;
    }
    return (res * sign);
}
