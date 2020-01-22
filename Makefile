CFLAGS= -W -Wall -ansi -pedantic -Wextra -Werror

NAME=	mendeltab

SRC=	$(wildcard *.c)

OBJ=	$(SRC:.c=.o)

all:	$(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)

re:	clean fclean all
