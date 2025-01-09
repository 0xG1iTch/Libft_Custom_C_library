NAME = push_swap
BNAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

GNL_DIR = get_next_line/
GNL_SRCS = get_next_line.c get_next_line_utils.c

SRCS = cost_move.c errors_handle.c initializing.c position.c psh_ops.c push_swap.c \
      rtt_ops.c sort.c split.c stck_helpers.c swp_ops.c

SRCB = cost_move.c errors_handle.c initializing.c position.c psh_ops.c \
      rtt_ops.c sort.c split.c stck_helpers.c swp_ops.c checker_bonus.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
OBJB = $(SRCB:.c=.o)

all: $(NAME)

bonus: $(BNAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(BNAME): $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) -o $(BNAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJB)

fclean: clean
	rm -f $(NAME) $(BNAME)

re: fclean all
