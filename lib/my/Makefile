##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Make my lib c.
##

SRC	=	my_putchar.c		\
		my_isneg.c		\
		my_put_nbr.c		\
		my_swap.c		\
		my_swap_char.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_getnbr.c		\
		my_compute_power_rec.c	\
		my_strcpy.c		\
		my_strncpy.c		\
		my_str_isint_float.c	\
		my_str_isnum.c	\
		my_revstr.c		\
		my_strstr.c		\
		my_strcmp.c		\
		my_strncmp.c		\
		my_strcat.c		\
		my_strcpy.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	+=	-Wall -Wextra -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp my.h ../../include/

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
