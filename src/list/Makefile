NAME = libmylist.a
SRC = new_node.c add_node.c add_elem.c append.c add_node_at.c print_list.c print_list_reverse.c remove_node.c \
	remove_last.c count_s_nodes.c empty_list.c print_int.c print_char.c print_string.c traverse_int.c \
	traverse_char.c traverse_string.c node_at.c elem_at.c remove_node_at.c debug_int.c debug_char.c \
	debug_string.c
OBJS = $(SRC:.c=.o)

CFLAGS = -I../../include --pedantic  -Wall -Werror 
LDFLAGS = -C

all: $(OBJS)
	ar -rc $(NAME) $(OBJS) 
	ranlib $(NAME)
	mv $(NAME) ../../lib

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f ../../lib/$(NAME)
	
re: fclean all

	
