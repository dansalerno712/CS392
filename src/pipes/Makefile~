NAME = minishell
SRC = main.c my_chdir.c my_execvp.c
OBJS = $(SRC:.c=.o)

CFLAGS = -I../../include --pedantic  -Wall -Werror  
LDFLAGS = -C

all: $(OBJS)
	cc -I../../include -L../../lib $(OBJS) -lmy -o $(NAME)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

	
