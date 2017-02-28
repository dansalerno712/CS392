NAME = libmy.a
SRC = my_char.c my_str.c my_int.c my_alpha.c my_digits.c my_find.c \
	my_rfind.c my_strlen.c my_revstr.c my_num_base.c my_strindex.c my_strrindex.c \
	my_strcat.c my_strcmp.c my_strncmp.c my_strcpy.c my_strdup.c my_strconcat.c \
	my_strncpy.c my_strnconcat.c my_vect2str.c my_str2vect.c my_atoi.c
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

	
