#include "sockettalk.h"
/* allocates memory for new struct, initiallizes, and returns */
struct client_pair *new_client_pair(int fd, char *username)
{
	struct client_pair* client;

	client = (struct client_pair*)malloc(sizeof(struct client_pair));
	client -> fd = fd;
	client -> username = username;

	return client;
}
