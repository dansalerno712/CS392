SERVERNAME = server
CLIENTNAME = client
SERVERSRC = get_char.c get_client_pid.c quit.c server.c
CLIENTSRC = client_quit.c send_char.c send_pid.c ack.c sig_alarm.c client.c
SERVEROBJS = $(SERVERSRC:.c=.o)
CLIENTOBJS = $(CLIENTSRC:.c=.o)

CFLAGS = -I../../include --pedantic  -Wall -Werror  
LDFLAGS = -C

all: server client

server: CFLAGS += -DSERVER
server: $(SERVEROBJS)
	cc -I../../include -L../../lib $(SERVEROBJS) -lmy -o $(SERVERNAME)

client: $(CLIENTOBJS)
	cc -I../../include -L../../lib $(CLIENTOBJS) -lmy -o $(CLIENTNAME)

clean:
	rm -f $(SERVEROBJS)
	rm -f $(CLIENTOBJS)

fclean: clean
	rm -f $(SERVERNAME)
	rm -f $(CLIENTNAME)

re: fclean all

