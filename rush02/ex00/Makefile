NAME = rush-02

SRCS = ./srcs/main.c ./srcs/init.c ./srcs/prints.c ./srcs/split.c ./srcs/utils-1.c ./srcs/utils-2.c

CC = cc

FLAGS = -Wall -Wextra -Werror -I./includes

RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re