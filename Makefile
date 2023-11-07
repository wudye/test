NAME = minitalk

NAMEC = client
NAMES = server
BONUS_NAMEC = client_bonus
BONUS_NAMES = server_bonus
MINI_LIBFT = mini_libft.a

SRCC_FILES = client.c
SRCS_FILES = server.c
BONUSC_FILES = client_bonus.c
BONUSS_FILES = server_bonus.c
SRC_DIR = src/
SRCC = $(addprefix $(SRC_DIR), $(SRCC_FILES))
SRCS = $(addprefix $(SRC_DIR), $(SRCS_FILES))
BONUSC = $(addprefix $(SRC_DIR), $(BONUSC_FILES))
BONUSS = $(addprefix $(SRC_DIR), $(BONUSS_FILES))
OBJC = ${SRCC:.c=.o}
OBJS = ${SRCS:.c=.o}
OBJBC = ${BONUSC:.c=.o}
OBJBS = ${BONUSS:.c=.o}

cc = cc
FLAGS = -Wall -Wextra -Werror 
INCLUDE = -I include

all:    $(NAMEC) $(NAMES)

$(NAMEC) : $(OBJC)
			@make -C mini_libft
			$(CC) $(CFLAGS) $(OBJC) $(INCLUDE) mini_libft/$(MINI_LIBFT) -o $(NAMEC)
$(NAMES) : $(OBJS)
			@make -C mini_libft
			$(CC) $(CFLAGS) $(OBJS) $(INCLUDE) mini_libft/$(MINI_LIBFT) -o $(NAMES)

bonus : $(BONUS_NAMEC) $(BONUS_NAMES)

$(BONUS_NAMEC) : $(OBJBC)
			@make -C mini_libft
			$(CC) $(CFLAGS) $(OBJBC) $(INCLUDE) mini_libft/$(MINI_LIBFT) -o $(BONUS_NAMEC)
$(BONUS_NAMES) : $(OBJBS)
			@make -C mini_libft
			$(CC) $(CFLAGS) $(OBJBS) $(INCLUDE) mini_libft/$(MINI_LIBFT) -o $(BONUS_NAMES)

clean :
			@make clean -C mini_libft
			${RM} ${OBJC}
			${RM} ${OBJS}
			${RM} ${OBJBS}
			${RM} ${OBJBS}

fclean : clean
			@make fclean -C mini_libft
			${RM} ${NAMEC}
			${RM} ${NAMES}
			${RM} ${BONUS_NAMEC}
			${RM} ${BONUS_NAMES}
			${RM} ${MINI_LIBFT}

re : fclean all

.PHONY : all bonus clean fclean re	

