/*
** EPITECH PROJECT, 2023
** str
** File description:
** myteams
*/

#include "server.h"

char *creat_str(int nb)
{
    char *str = malloc((nb + 1) * sizeof(char));

    str[nb] = 0;
    return (str);
}

int long_len(long int nb)
{
    int len = 1;

    if (nb < 0) {
        len++;
        nb *= -1;
    }
    while (nb > 9) {
        nb /= 10;
        len++;
    }
    return (len);
}

long int long_to_str(char  *str)
{
    long int res = 0;
    int signe = 1;
    int i = 0;

    if (!str)
        return (res);
    if (str[0] && str[0] == '-') {
        signe *= -1;
        i++;
    }
    while (str[i]) {
        res *= 10;
        res += str[i] - 48;
        i++;
    }
    return (res * signe);
}
