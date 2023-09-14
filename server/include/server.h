/*
** EPITECH PROJECT, 2023
** server
** File description:
** myteams
*/

#pragma once

    #include "../../include.h"
    #include "logging_server.h"

enum context {home, team, channel, thread};

typedef struct {
    char *buf;
    int rd;
    int wt;
    unsigned int length;
} circular_buf;

typedef struct reply_s {
    char *team_id;
    char *message;
    char *thread_id;
    char *author_id;
    time_t timestamp;
} reply_t;

typedef struct linked_reply_s {
    reply_t *ptr;
    struct linked_reply_s *next;
} linked_reply_t;

typedef struct message_s {
    char *sender_id;
    time_t timestamp;
    char *message;
} message_t;

typedef struct linked_message_s {
    message_t *ptr;
    struct linked_message_s *next;
} linked_message_t;

typedef struct thread_s {
    char *id;
    char *author_id;
    char *title;
    char *message;
    time_t timestamp;
    linked_reply_t *replies;
} thread_t;

typedef struct linked_thread_s {
    thread_t *ptr;
    struct linked_thread_s *next;
} linked_thread_t;

typedef struct channel_s {
    char *id;
    char *name;
    char *description;
    linked_thread_t *threads;
} channel_t;

typedef struct linked_channel_s {
    channel_t *ptr;
    struct linked_channel_s *next;
} linked_channel_t;

typedef struct team_s {
    char *id;
    char *name;
    char *description;
    linked_channel_t *channels;
    struct linked_user_s *subscribed;
} team_t;

typedef struct linked_team_s {
    team_t *ptr;
    struct linked_team_s *next;
} linked_team_t;

typedef struct user_s {
    char *id;
    char *username;
    linked_team_t *subscribed;
    team_t *current_team;
    channel_t *current_channel;
    thread_t *current_thread;
    enum context contxt;
    int tracker;
} user_t;

typedef struct linked_user_s {
    user_t *ptr;
    struct linked_user_s *next;
} linked_user_t;

typedef struct chat_s {
    linked_message_t *conv;
    user_t *user1;
    user_t *user2;
} chat_t;

typedef struct linked_chat_s {
    chat_t *ptr;
    struct linked_chat_s *next;
} linked_chat_t;

typedef struct linked_client_t {
    int fd;
    circular_buf *write_buf;
    circular_buf *read_buf;
    user_t *user;
    struct sockaddr_in data_sin;
    int quitting;
    struct linked_client_t *next;
} linked_client;

typedef struct {
    uint16_t port;
    int socket_fd;
    fd_set read_fd;
    fd_set write_fd;
    fd_set exe_fd;
    linked_client *head;
    linked_user_t *users;
    linked_team_t *teams;
    linked_chat_t *chats;
    struct command_s **commands;
} server_t;

struct command_s;
typedef struct command_s {
    char *name;
    void (*ptr)(server_t *, linked_client *, char **);
    struct command_s *next;
} command_t;

// COMMANDS FUNCTION PROTOTYPE

void login_command(server_t *server, linked_client *client, char **command);
void logout_command(server_t *server, linked_client *client, char **command);
void users_command(server_t *server, linked_client *client, char **command);
void user_command(server_t *server, linked_client *client, char **command);
void send_command(server_t *server, linked_client *client, char **command);
void messages_command(server_t *server, linked_client *client, char **command);
void use_command(server_t *server, linked_client *client, char **command);
void create_command(server_t *server, linked_client *client, char **command);
void list_command(server_t *server, linked_client *client, char **command);
void subscribed_command(server_t *ser, linked_client *clie, char **command);
void subscribe_command(server_t *server, linked_client *client, char **command);
void unsubscribe_command(server_t *serv, linked_client *client, char **command);
void info_command(server_t *server, linked_client *client, char **command);

// OTHER FUNCTIONS PROTOTYPES

int write_message(int client_fd, char *msg);
int emit_error(server_t *server, char *msg);
int is_num(char c);
int is_nbr(char *str);
uint16_t getshort(char *str);
int check_valid_arg(int argc, char **argv);
int handle_args(int argc, char **argv, server_t **server);
void initialize_fd(int fd, fd_set *read_fd, fd_set *write_fd,
    fd_set *exe_fd);
int bind_and_listen(server_t *server);
int check_new_client(server_t *server, fd_set *read_fd);
int check_client_write(server_t *server, fd_set *write_fd,
    linked_client *client);
int mainloop(server_t *server);
void print_help(void);
int check_flags(int argc, char **argv);
circular_buf *create_buffer(unsigned int length);
char *circular_copy(circular_buf *buf, int n);
void write_buffer(circular_buf *buf, char *src, int len);
char *read_buffer(circular_buf *buf);
void destroy_buffer(circular_buf *buf);
int check_client_read(server_t *server, fd_set *read_fd,
    linked_client *client);
int get_command_nb(circular_buf *buf);
char **get_command(circular_buf *buf);
char **creat_tab(int len);
void display_tab(char **tab);
int tab_len(char **tab);
void free_tab(char **tab);
char **split(char *str, char separator);
char **split_command(char *str);
int valid_command_format(char *str);
char *creat_str(int nb);
long int long_to_str(char  *str);
int check_command_args(linked_client *client, int arg_nb[2], int auth,
    char **command);
enum context get_context(user_t *user);
void set_context(user_t *user, team_t *team, channel_t *cha, thread_t *thr);

// PRINT
void print_teams(circular_buf *output, linked_team_t *teams);
void print_channel(circular_buf *output, linked_channel_t *channels);
void print_thread(circular_buf *output, linked_thread_t *threads);
void print_reply(circular_buf *output, linked_reply_t *replies);
void print_messages(circular_buf *output, linked_message_t *replies);
void print_users(circular_buf *output, linked_user_t *users);

// REPLY
reply_t *init_reply(char *author_id, char *msgbody, char *thrid, char *teaid);
void push_reply(linked_reply_t **head, reply_t *reply);
void pop_reply(linked_reply_t **head, reply_t *reply);
void destroy_reply(reply_t *reply);

// MESSAGE
message_t *init_message(char *sender_id, char *msgbody);
void push_message(linked_message_t **head, message_t *new);
void pop_message(linked_message_t **head, message_t *reply);
void destroy_message(message_t *reply);

// USER
user_t *init_user(char *username);
void push_user(linked_user_t **head, user_t *new);
void pop_user(linked_user_t **head, user_t *user);
void destroy_user(user_t *user);
int user_subscribed(user_t *user, team_t *team);
int user_online(server_t *server, char *id);

// CLIENT
linked_client *create_elem(int fd);
void push_back(linked_client **head, linked_client *new);
void pop_client(linked_client **head, linked_client *client);
void destroy_client(linked_client *client);
int add_new_client(server_t *server, int client_fd);
int check_status(linked_client *head, char *username);

// COMMAND
void init_commands(server_t *server);
command_t *init_command(char *name, void (*ptr)(server_t *,
    linked_client *, char **));
void push_command(command_t **head, char *name, void (*ptr)(server_t *,
    linked_client *, char **));
void pop_command(command_t **head, command_t *command);
void destroy_command(command_t *command);

// CHAT
chat_t *init_chat(user_t *user1, user_t *user2);
void push_chat(linked_chat_t **head, chat_t *chat);
void pop_chat(linked_chat_t **head, chat_t *command);
void destroy_chat(chat_t *command);
chat_t *create_discussion(server_t *server, user_t *user1, user_t *user2);

// TEAM
team_t *init_team(char *name, char *description);
void push_team(linked_team_t **head, team_t *new);
void pop_team(linked_team_t **head, team_t *team);
void destroy_team(team_t *team);

// CHANNEL
channel_t *init_channel(char *name, char *description);
void push_channel(linked_channel_t **head, channel_t *new);
void pop_channel(linked_channel_t **head, channel_t *team);
void destroy_channel(channel_t *team);

// THREAD
thread_t *init_thread(char *title, char *msgbody, char *author_id);
void push_thread(linked_thread_t **head, thread_t *new);
void pop_thread(linked_thread_t **head, thread_t *team);
void destroy_thread(thread_t *team);

// GET
team_t *get_team(server_t *server, char *id);
channel_t *get_channel(team_t *team, char *id);
thread_t *get_thread(channel_t *channel, char *id);

// EVENT
void send_all_users(server_t *server, char *msg);
void send_all_team_users(server_t *server, team_t *team, char *msg);
void send_to_user(server_t *server, char *uuid, char *msg);

// FORMAT
char *format_one_string(char *signal, char *uuid);
char *format_two_string(char *signal, char *str1, char *str2);
char *format_three_string(char *signal, char *str1, char *str2, char *str3);
char *describe_thread(char *signal, thread_t *thread);
char *describe_reply(char *signal, reply_t *reply);

// FIND
user_t *find_user_by_id(linked_user_t *users, char *id);
team_t *find_team_by_id(linked_team_t *teams, char *id);
channel_t *find_channel_by_id(linked_channel_t *channels, char *id);
thread_t *find_thread_by_id(linked_thread_t *threads, char *id);

user_t *find_user_by_name(linked_user_t *users, char *username);
team_t *find_team_by_name(linked_team_t *teams, char *teamname);
channel_t *find_channel_by_name(linked_channel_t *channels, char *channelname);
thread_t *find_thread_by_name(linked_thread_t *threads, char *threadname);
chat_t *find_discussion_by_users(linked_chat_t *user, user_t *user1,
    user_t *user2);

// SAVE
void saveguard_server(server_t *server);
void save_team(FILE *fd, team_t *teams);
void save_channel(FILE *fd, channel_t *channels);
void save_thread(FILE *fd, thread_t *threads);
void save_reply(FILE *fd, reply_t *threads);
void save_user(FILE *fd, user_t *user);
void save_message(FILE *fd, message_t *conv);
void save_conv(FILE *fd, chat_t *conv);

// LOAD
void load_convs(char *path, linked_chat_t **chats, linked_user_t *users);
void load_users(char *path, linked_user_t **users, linked_team_t *teams);
void load_teams(char *path, linked_team_t **teams);
void load_backup(server_t *server);

// LOAD FILL
void fill_field(char **dest, char *src, int *step);
void fill_reply(char *line, reply_t *reply, int *step);
void fill_thread(char *line, thread_t *thread, int *step);
void fill_channel(char *line, channel_t *channel, int *step);
void fill_team(char *line, team_t *team, int *step);

// DETAIL
void detail_team(circular_buf *output, team_t *team);
void detail_channel(circular_buf *output, channel_t *channel);
void detail_thread(circular_buf *output, thread_t *thread);
void detail_reply(circular_buf *output, reply_t *reply);
void detail_messages(circular_buf *output, message_t *conv);
void detail_user(circular_buf *output, user_t *user);
