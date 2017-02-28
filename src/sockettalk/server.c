#include "sockettalk.h"

int main(int argc, char **argv)
{
	fd_set read_fds;
	struct sockaddr_in serveraddr;
	struct sockaddr_in clientaddr;
	int listener, newfd, bytes_read, port;
	socklen_t clilen;
	char buf[MAX_BUFFER_SIZE];
	int i, k;
	char *message;
	struct client_pair *temp;
	/* usage */
	if (argc != 2)
	{
		my_str("Usage: ./server [port]\n");
		exit(0);
	}
	gl_head = (struct s_node*)malloc(sizeof(struct s_node));   
	/* get port */
	port = my_atoi(argv[1]);
	if (port < 0)
	{
		my_str("Invalid port\n");
		exit(EXIT_FAILURE);
	}
	/* sertup fdset */
	FD_ZERO(&gl_master);
	FD_ZERO(&read_fds);
	/* add listener */
	if ((listener = socket(AF_INET, SOCK_STREAM, 0)) < 0)
		perror("socket() error"), exit(EXIT_FAILURE);
	my_str("Socket successfully created\n");
	/* sertup servaddr */
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = INADDR_ANY;
	serveraddr.sin_port = htons(port);
	memset(&(serveraddr.sin_zero), '\0', 8);
	/* bind listener */
	if (bind(listener, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0)
		perror("bind() error"), exit(EXIT_FAILURE);
	my_str("bind successful\n");
	/* listen on listener */
	if(listen(listener, 5) < 0)
		perror("listen() failure"), exit(EXIT_FAILURE);
	my_str("listen successful\n");
	/* add listener to master set */
	FD_SET(listener, &gl_master);
	gl_max_fd = listener;
	/* loop */
	while (1)
	{
		/* select */
		read_fds = gl_master;

		if (select(gl_max_fd + 1, &read_fds, NULL, NULL, NULL) < 0)
			perror("select() failure"), exit(EXIT_FAILURE);
		/* find what triggered select */
		for (i = 3; i <= gl_max_fd; i++)
		{
			if (FD_ISSET(i, &read_fds))
			{
				/* if new connection */
				if (i == listener)
				{
					/*accept new connection */
					clilen = sizeof(clientaddr);
					if ((newfd = accept(listener,
							    (struct sockaddr *)&clientaddr,
							    &clilen)) < 0)
						perror("accept() error"), exit(EXIT_FAILURE);
					/* get username */
					bytes_read = read(newfd, buf, MAX_BUFFER_SIZE - 1);
					if (bytes_read < 0)
						perror("read error"), exit(EXIT_FAILURE);
					buf[bytes_read] = '\0';
					/* add to fdset */
					FD_SET(newfd, &gl_master);
					if (newfd > gl_max_fd)
						gl_max_fd = newfd;
					/* add to linked list */
					add_elem(new_client_pair(newfd, my_strdup(buf)), &gl_head);
					/* tell clients a new connection */
					message = my_strconcat(buf, " has connected\n");
					send_message(listener, message);
					my_str(message);
				}
				else
				{
					/* got message */
					bytes_read = read(i, buf, MAX_BUFFER_SIZE - 1);
					/* if disconnect */
					if (bytes_read == 0)
					{
						/* remove from linked list */
						for (k = 0; k < count_s_nodes(gl_head); k++)
						{
							temp = (struct client_pair*)elem_at(gl_head, k);
							if (temp -> fd == i)
							{
								message = temp -> username;
								free(remove_node_at(&gl_head, k));
								break;
							}
						}
						/* tell clients of closure */
						message = my_strconcat(message, " has disconnected\n");
						send_message(listener, message);
						my_str(message);
						FD_CLR(i, &gl_master);
						close(i);
						continue;
					}
					if (bytes_read < 0)
						perror("read error"), exit(EXIT_FAILURE);
					buf[bytes_read] = '\0';
					/* process message */
					message = process_message(i, buf);
					/* if valid command */
					if (message != NULL)
					{
						my_str(message);
						/* send to all clients */
						send_message(listener, message);
					}
				}
				
			}
				    
		}
	}
	return 0;
}
