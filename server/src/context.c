/*
** EPITECH PROJECT, 2023
** context
** File description:
** myteams
*/

#include "server.h"

enum context get_context(user_t *user)
{
    int result = 0;

    if (user->current_team) {
        result++;
        if (user->current_channel)
            result++;
    }
    if (result == 2 && user->current_thread)
        result++;
    switch (result) {
        case (1):
            return (team);
        case (2):
            return (channel);
        case (3):
            return (thread);
    }
    return (home);
}
