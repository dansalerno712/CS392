NAME = my_select
SRC = init_scr.c move_up.c move_down.c move_left.c move_right.c select.c
OBJS = $(SRC:.c=.o)

CFLAGS = -I../../include --pedantic  -Wall -Werror -std=c99
LDFLAGS = -C

all: $(OBJS)
	cc -I../../include -L../../lib $(OBJS) -lmy -lncurses -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

