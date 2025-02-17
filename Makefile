NAME = push_swap

CC = clang

SRCS =	push_swap.c\
		push_swap_utils.c\
		sort_small_stacks.c\
		simplify.c\
		parsing1.c\
		parsing2.c\
		push.c\
		swap.c\
		rotate.c\
		rrotate.c

OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a
FLAGS = -Wall -Wextra -Werror -g

all: $(NAME) libft

$(NAME): $(LIBFT) $(OBJS) 
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C ./libft

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C ./libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean all re fclean libft
