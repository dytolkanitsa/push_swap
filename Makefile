NAME = push_swap

HEADER = push_swap.h

LIST = if_sort.c operations.c find_amount.c\
		operations2.c operations3.c push_swap.c \
		sort_five.c utils.c utils2.c utils3.c utils4.c \
		get_commands.c ft_split.c utils5.c utils6.c

FLAGS = -Wall -Wextra -Werror

OBJ = $(LIST:.c=.o)

.PHONY : all clean fclean re


all : $(NAME)

${NAME} : ${LIST}
	gcc $(FLAGS) -o $(NAME) ${LIST}

%.o : %.c $(HEADER)
	gcc -c $< -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all