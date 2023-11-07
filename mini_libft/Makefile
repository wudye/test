NAME = mini_libft.a
SRC = util.c

OBJECTS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME):   $(OBJECTS)
		ar rcs $(NAME) $(OBJECTS)

all:       $(NAME)

clean:
		rm -f $(OBJECTS)
fclean:    clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
