##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## myftp
##

NAME = myteams_server

CC	=	gcc

PRINT	=	echo -e

NO_PRINT = --no-print-directory

LIBPATH = ../libs/myteams/

LIB = myteams

SRC = src/command_func/create_command.c \
	src/command_func/info_command.c \
	src/command_func/list_command.c \
	src/command_func/log_command.c \
	src/command_func/message_command.c \
	src/command_func/save_command.c \
	src/command_func/subscribe_command.c \
	src/command_func/use_command.c \
	src/command_func/user_command.c \
	src/linked_func/linked_channel.c \
	src/linked_func/linked_chat.c \
	src/linked_func/linked_client.c \
	src/linked_func/linked_command.c \
	src/linked_func/linked_message.c \
	src/linked_func/linked_reply.c \
	src/linked_func/linked_teams.c \
	src/linked_func/linked_thread.c \
	src/linked_func/linked_user.c \
	src/channel.c \
	src/chat.c \
	src/circular_buffer.c \
	src/command_management.c \
	src/context.c \
	src/display_details.c \
	src/error_handling.c \
	src/event.c \
	src/find_by_id.c \
	src/find_by_property.c \
	src/flag_management.c \
	src/format.c \
	src/load_conv.c \
	src/load.c \
	src/loading_fill.c \
	src/load_team.c \
	src/load_user.c \
	src/mainloop.c \
	src/message.c \
	src/parse_command.c \
	src/print_other.c \
	src/print.c \
	src/reply.c \
	src/save_conv.c \
	src/save_team.c \
	src/save_user.c \
	src/server.c \
	src/split.c \
	src/str.c \
	src/tab.c \
	src/teams.c \
	src/thread.c \
	src/tools.c \
	src/user_tools.c \
	src/user.c

RM		=	rm -f

INCLUDE	=	-I./include/ -I./$(LIBPATH)

DEBUGFLAG	=	-g3

LINKLIB	=	-L./$(LIBPATH) -l$(LIB)

USELESS_F	=	*~

VG		=	vgcore.*

FLAGS	=	$(INCLUDE) $(DEBUGFLAG) $(LINKLIB) -luuid

OBJ	=	$(SRC:.c=.o)

$(OBJDIR)%.o:	%.c
	@$(CC) $(FLAGS) -o $@ -c $<
	@if test -s $*.c; then \
	$(PRINT) "\033[01m\033[35m Compiling \033[00m\
	\033[36m$(SRCPATH)$*.c\033[032m  [OK]\033[00m";\
	else \
	$(PRINT) "\033[01m\033[33m Compiling \033[00m\
	\033[36m$(SRCPATH)$*.c\033[00m\  [Error]"; fi

$(NAME):		$(OBJ)
	@$(PRINT) "\033[01m\033[31mLinking ...\033[00m"
	@$(CC) $(OBJ) -o $(NAME) $(FLAGS)
	@cp $(NAME) ./../
	@$(PRINT) "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

all:	$(NAME)

debug:	$(OBJ)
	@$(PRINT) "\033[01m\033[31mLinking ...\033[00m"
	@$(CC) $(OBJ) -o $(NAME) $(FLAGS)
	@$(PRINT) "\033[01m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	@$(REV_CCLIB)
	@$(RM) $(OBJ)
	@$(RM) $(USELESS_F)
	@$(RM) $(VG)
	@$(PRINT) "\033[1;93mRemoving objects ...\033[0m"

fclean: 	clean
	@$(RM) $(NAME)
	@$(PRINT) "\033[1;93mRemoving binary : {${NAME}} ...\033[0m"
	@$(PRINT) "\033[1;92mPROCESS FINISHED [OK]\033[0m"

re:		fclean all

help:
	@$(PRINT) "[press make for compile the project]"

.PHONY:			all debug clean fclean re help
