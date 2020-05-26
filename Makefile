##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## The makefile for a stumper.
##

SRC	=	main.c

OBJ	=	$(SRC:.c=.o)

NAME	=	105torus

CFLAGS	+=	-Wall -Wextra -g

LDFLAGS	=	-Llib/my 	\
		-lmy		\
		-lm

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)
	make -C lib/my clean

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean

re:	fclean relib all

relib:
	make -C lib/my re

.PHONY: re clean fclean all relib
