NAME = bsq

SRCS = ./srcs/bsq_algorithm.c ./srcs/bsq_check_input.c ./srcs/bsq_init.c ./srcs/bsq_stdin.c ./srcs/bsq_utils.c ./srcs/main.c ./srcs/lists.c

CC = cc

FLAGS = -Wall -Wextra -Werror -I./includes

RM = rm -f

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) $(OBJS)

re: fclean all

.PHONY: all fclean re