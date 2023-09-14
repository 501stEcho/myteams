/*
** EPITECH PROJECT, 2022
** client.h
** File description:
** header
*/

#pragma once

    #include "../../libs/myteams/logging_client.h"
    #include "../../include.h"

    #define USAGE "USAGE: ./myteams_cli ip port\n\
    ip is the server ip address on which the server socket listens\n\
    port is the port number on which the server socket listens\n"

    #define HELPP "USAGE:\n\
            /help display help\n\
            /login [""username""] log with user\n\
            /logout disconnect\n"

    #define R_BUFF(x, i)   x + i >= 1024 ? x + i - 1024 : x + i
    #define BUFF_SIZE 1024

typedef struct command_s {
    int *code;
    void (*ptr)(char **);
    struct command_s *next;
}command_t;

typedef struct {
    char *buf;
    int rd;
    int wt;
    unsigned int length;
} circular_buf;

typedef struct client_s {
    int ac;
    int port;
    int socket_fd;
    int head_socket;
    int read_socket;
    int len_socket;
    int head_stdin;
    int read_stdin;
    int len_stdin;
    char *ip;
    char **av;
    char *buff_stdin;
    char *buff_socket;
    char ***tab;
    circular_buf *write_buf;
    circular_buf *read_buf;
    fd_set read_fd;
    fd_set write_fd;
    fd_set exe_fd;
    struct sockaddr_in adress;
} client_t;

int client_start(int ac, char **av);
int check_server_response(client_t *client, fd_set *read_fd);
int read_server_response(client_t *client);
int check_server_write(client_t *client, fd_set *write_fd);
int send_server_command(client_t *client);
char ***to_triple_star(char *buff);
int redirect_function(char ***buf);
char *getcmd(void);
int list_function(int code, char ***buf, int idx);
int create_function(int code, char ***buf, int idx);
int feature_function(int code, char ***buf, int idx);
int info_function(int code, char ***buf, int idx);
int error_function(int code, char ***buf, int idx);
void do_cmd(char *code, char ***args, int line);
void read_client(client_t *client);
int write_message(int client_fd, char *msg);
char ***malloc_tab(char *buff, int line);
void print_tab(char ***tab);
bool is_number(char *str);
char *correct_str(char *str);
char *good_str(char *str, char *cat, int nb);
void fill_tab(char ***tab, char *buff, int nbr_l);

// circular buffer
circular_buf *create_buffer(unsigned int length);
char *circular_copy(circular_buf *buf, int n);
void write_buffer(circular_buf *buf, char *src, int len);
char *read_buffer(circular_buf *buf);
void destroy_buffer(circular_buf *buf);
