##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

SRC	=	usage.c	\
		my_swap.c	\
		my_inseg.c	\
		my_strlen.c	\
		read_file.c	\
		check_num.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_getnbr.c	\
		my_strdup.c	\
		my_calloc.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_putstrn.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		strcpy_end.c	\
		my_is_prime.c	\
		putstr_error.c	\
		my_strupcase.c	\
		my_clear_str.c	\
		my_str_isnum.c	\
		my_strlowcase.c	\
		my_str_isupper.c	\
		my_putnbr_base.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_strcapitalize.c	\
		my_sort_int_array.c	\
		my_str_isprintable.c	\
		my_str_to_word_array.c	\
		my_str_to_word_array_char.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-g3

NAME 	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
