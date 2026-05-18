NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	utils.c \
	free.c \
	split.c \
	parsing.c \
	init_stack.c \
	stack_utils.c \
	stack_utils2.c \
	sa_sb_ss.c \
	pa_pb.c \
	ra_rb_rr.c \
	rra_rrb_rrr.c \
	small_sort.c \
	radix_sort.c \
	sort.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
