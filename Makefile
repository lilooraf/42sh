##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c	\
		src/alias_tools.c	\
		src/alias_tools_2.c	\
		src/alias_check.c	\
		src/my_alias.c	\
		src/separe.c	\
		src/my_exec.c	\
		src/my_pipe.c	\
		src/redirect.c	\
		src/my_setenv.c	\
		src/minishell.c	\
		src/my_unsetenv.c	\
		src/cd_minishell.c	\
		src/ftc_minishell.c	\
		src/ftc_minishell_2.c	\
		src/ftc_minishell_3.c	\
		src/ftc_minishell_4.c

OBJ	=	$(SRC:.c=.o)

NAME 	=	42sh

CFLAGS	=	-L lib/my/ -lmy -g3 -Iinclude

all:	$(NAME)

$(NAME):	$(OBJ)
	@make -C ./lib/my/
	@gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	@make clean -C ./lib/my/
	@rm -f $(OBJ)

fclean:	clean
	@make fclean -C ./lib/my/
	@rm -f $(NAME)

re:	fclean all

