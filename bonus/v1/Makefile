##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

NAME	=	setting_up

SRC	=	src/main.c		\
		src/lib.c		\
		src/str.c		\
		src/conv.c		\
		src/solve.c		\

OBJ	=	$(SRC:.c=.o)
CFLAGS	=	-Wall -Wextra -Werror -I./include -g
FAST	=	-O1 -flto -march=native

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
