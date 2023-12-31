##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME	=	setting_up

SRC	=	src/main.c		\
		src/str.c		\
		src/read.c		\
		src/genverif.c	\
		src/initnodes.c	\
		src/forward.c	\
		src/solve.c		\

OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -I./include -g3
FAST	=	-Ofast -fno-builtin -flto -march=native

#all:		$(NAME)
all:		fast

$(NAME):	$(OBJ)
		gcc  $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS)

fast:	fclean $(SRC)
		gcc  $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS) $(FAST)

re:	fclean all

fclean:	clean
	rm -f $(NAME)

clean:
	rm -f $(OBJ)
