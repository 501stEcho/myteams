/*
** EPITECH PROJECT, 2023
** interpret
** File description:
** code
*/

#include "../include/client.h"

void funct(int code, char ***args, int i, int j)
{
    static int (*function[])(int code, char ***buf, int idx) = {
        &feature_function, &feature_function, &feature_function, \
        &feature_function, &feature_function, &feature_function, \
        &feature_function, &feature_function, &feature_function, \
        &create_function, &create_function, \
        &create_function, &create_function, &create_function, &list_function, \
        &list_function, &list_function, &list_function, &info_function, \
        &info_function, &info_function, &info_function, &error_function, \
        &error_function, &error_function, &error_function, &error_function, \
        &error_function, NULL};
    (*function[i])(code, args, j);
}

void check_code(char *code, char ***args, int j)
{
    static const char *func[29] = {"102", "104", "106", "108", "110", "112",\
    "114", "116", "118", "120", "202", "204", "206", "208", "302", "304",\
    "306", "308", "402", "404", "406", "408", "501", "503", "505", "507", \
    "509", "511", NULL};

    for (int i = 0; func[i] != NULL; i++) {
        if (strcasecmp(code, func[i]) == 0) {
            funct(atoi(code), args, i, j);
            break;
        }
    }
}

void do_cmd(char *code, char ***args, int line)
{
    if (atoi(code) == 509)
        client_error_unauthorized();
    if (atoi(code) == 511)
        client_error_already_exist();
    else {
        for (int j = 1; args[j]; j++) {
            check_code(code, args, j);
        }
    }
}
