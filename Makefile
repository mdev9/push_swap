NAME = push_swap

CC = clang

SRCS =	push_swap.c\
		push_swap_utils.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) 

.c.o:
	$(CC) $(FLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f a.out libft.a

re: fclean all

.PHONY: clean all re fclean
