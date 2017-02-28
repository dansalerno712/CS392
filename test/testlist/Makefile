NAME = testlist

SRC = listmain.c
OBJ = $(SRC:.c=.o)

CFLAGS = -I../../include 
LDFLAGS = -C

all: $(OBJ)
	cc -L../../lib $(OBJ) -o $(NAME) -lmylist -lmy
	
clean:
	rm -f $(OBJ)
	rm -f $(NAME)        

re: clean all
