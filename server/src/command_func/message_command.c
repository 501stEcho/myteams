/*
** EPITECH PROJECT, 2023
** log_command
** File description:
** myteams
*/

#include "server.h"

void send_command(server_t *server, linked_client *client, char **args)
{
    user_t *target;
    chat_t *chat;
    int param[] = {3, 3};
    if (!check_command_args(client, param, 1, args))
        return;
    target = find_user_by_id(server->users, args[1]);
    if (!target)
        return (write_buffer(client->write_buf, format_one_string(UNKNOW_USER,
            args[1]), -1));
    chat = find_discussion_by_users(server->chats, client->user, target);
    if (!chat)
        chat = create_discussion(server, client->user, target);
    push_message(&chat->conv, init_message(client->user->id, args[2]));
    server_event_private_message_sended(client->user->id, target->id,
        args[2]);
    send_to_user(server, target->id, format_two_string(SEND_MSG_S,
        client->user->id, args[2]));
}

void messages_command(server_t *server, linked_client *client, char **command)
{
    chat_t *chat;
    reply_t *reply;
    user_t *target;
    char *src;
    int n, args[] = {2, 2};

    if (!check_command_args(client, args, 1, command))
        return;
    target = find_user_by_id(server->users, command[1]);
    if (!target)
        return (write_buffer(client->write_buf, format_one_string(UNKNOW_USER,
            command[1]), -1));
    chat = find_discussion_by_users(server->chats, client->user, target);
    write_buffer(client->write_buf, LIST_MSG_S, -1);
    if (chat)
        print_messages(client->write_buf, chat->conv);
    write_buffer(client->write_buf, "\r\n", 2);
}
