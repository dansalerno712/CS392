NAME = testmy

SRC = main.c
OBJ = $(SRC:.c=.o)

CFLAGS = -I../../include 
LDFLAGS = 

all: $(OBJ)
	cc -L../../lib $(OBJ) -o $(NAME) -lmy
	
clean:
	rm -f $(OBJ)
	rm -f $(NAME)        
