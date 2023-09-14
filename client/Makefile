##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## myftp
##

NAME = myteams_cli

CC	=	gcc

PRINT	=	echo -e

NO_PRINT = --no-print-directory

LIBPATH = ../libs/myteams/

LIB = myteams

SRC =	src/main.c	\
	src/tab.c	\
	src/utils.c	\
	src/buffer.c	\
	src/server_com.c	\
	src/client_loop.c	\
	src/code_function.c	\
	src/interpret_code.c	\
	src/circular_buffer.c \
	src/command_parsing.c

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
