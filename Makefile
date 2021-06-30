NAME = push_swap

HEADER = push_swap.h

SRC = if_sort.c operations.c find_amount.c\
		operations2.c operations3.c push_swap.c \
		sort_five.c utils.c utils2.c utils3.c utils4.c \
		get_commands.c ft_split.c utils5.c utils6.c

FLAGS = -Wall -Wextra -Werror

OBJ = ${SRC:.c=.o}

all : ${NAME}

%.o : %.c $(HEADER)
	gcc ${FLAGS} -c $< -o $@

${NAME} : ${SRC} ${OBJ}
	gcc ${FLAGS} -o ${NAME} ${SRC}

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re