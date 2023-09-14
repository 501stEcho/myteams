/*
** EPITECH PROJECT, 2023
** include
** File description:
** myteams
*/

#pragma once

    #define _GNU_SOURCE

    #include <sys/types.h>
    #include <sys/socket.h>
    #include <sys/stat.h>
    #include <arpa/inet.h>
    #include <netinet/in.h>
    #include <netinet/ip.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <dirent.h>
    #include <errno.h>
    #include <limits.h>
    #include <stdlib.h>
    #include <dirent.h>
    #include <stdbool.h>
    #include <uuid/uuid.h>

    #define MAX_NAME_LENGTH 32
    #define MAX_DESCRIPTION_LENGTH 255
    #define MAX_BODY_LENGTH 512

    //Signal Code

    // FEATURE:
    #define LOGIN_S "102\n"
    #define LOGOUT_S "104\n"
    #define USER_LIST_S "106\n"
    #define USER_DETAIL_S "108\n"
    #define SEND_MSG_S "110\n"
    #define LIST_MSG_S "112\n"
    #define SUB_S "114\n"
    #define SUB_TEAMS_S "116\n"
    #define SUB_LIST_S "118\n"
    #define UNSUB_S "120\n"

    //CREATE:
    #define CREATE_TEAM_S "202\n"
    #define CREATE_CHAN_S "204\n"
    #define CREATE_THR_S "206\n"
    #define CREATE_REP_S "208\n"

    //LIST:
    #define LIST_TEAM_S "302\n"
    #define LIST_CHAN_S "304\n"
    #define LIST_THR_S "306\n"
    #define LIST_REP_S "308\n"

    //INFO:
    #define LOGIN_USR_DET_S "402\n"
    #define SELECT_TEAM_DET_S "404\n"
    #define SELECT_CHAN_DET_S "406\n"
    #define SELECT_REP_DET_S "408\n"

    //ERROR
    #define UNKNOW_TEAM "501\n"
    #define UNKNOW_CHAN "503\n"
    #define UNKNOW_THREAD "505\n"
    #define UNKNOW_USER "507\n"
    #define UNAUTHORIZED "509\n\r\n"
    #define ALREADY_EXIST "511\n\r\n"
