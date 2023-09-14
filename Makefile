##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## myftp
##

SERVER = myteams_server

CLIENT = myteams_cli

NO_PRINT = --no-print-directory

RM = rm -f

all:
	@make -C ./server $(NO_PRINT)
	@make -C ./client $(NO_PRINT)

clean:
	@make clean -C ./server $(NO_PRINT)
	@make clean -C ./client $(NO_PRINT)
	@$(RM) vgcore.*

fclean:	clean
	@$(RM) $(SERVER)
	@$(RM) $(CLIENT)
	@make fclean -C ./server $(NO_PRINT)
	@make fclean -C ./client $(NO_PRINT)

re:	fclean all

.PHONY: all clean fclean re
