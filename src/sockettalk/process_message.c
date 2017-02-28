#include "sockettalk.h"

char *process_message(int fd, char *message)
{
	struct client_pair *temp;
	int k, i;
	char *ret;
	char *check; /* check stores the first word of message to check for valid
			special commands */
	/* get correct node from linked list */
	for (k = 0; k < count_s_nodes(gl_head); k++)
	{
		temp = (struct client_pair*)elem_at(gl_head, k);
		if (temp -> fd == fd)
		{
			break;
		}
	}
	/* save current username */
	ret = temp -> username;
	/* populate check */
	check = my_strdup(message);
	for (i = 0; check[i] != '\0'; i++)
	{
		if (check[i] == ' ' || check[i] == '\t')
			check[i] = '\0';
	}
	/* /exit command */
	if (my_strcmp(check, "/exit") == 0)
	{
		/* remove from linked list, close, then remove from set */
		free(remove_node_at(&gl_head, k));
		FD_CLR(fd, &gl_master);
		close(fd);

		ret = my_strconcat(ret, " has disconnected\n");
		return ret;
	}
	else if (my_strcmp(check, "/nick") == 0)
	{
		/* if they dont provide a username, tell them */
		if (my_strlen(message) <= 6)
		{
			ret = "Error: invalid username\n";
			/* if invalid, tell client */
			if (write(fd, ret, my_strlen(ret)) < 0)
				perror("write error"), exit(EXIT_FAILURE);

			return NULL;
		} /* send message */
		else
		{
			message += 6;
			temp -> username = my_strdup(message);
			ret = my_strconcat(ret, " has changed their username to ");
			ret = my_strconcat(ret, message);
			ret = my_strconcat(ret, "\n");
			return ret;
		}
	}
	else if (my_strcmp(check, "/me") == 0)
	{
		/* if they just type /me, send username attachd to newline */
		if (my_strlen(message) == 3)
		{
			ret = my_strconcat(ret, "\n");
			return ret;
		}
		else
		{
			/* get message, go one more to skip space */
			message += 4;
			/* dont add colon */
			ret = my_strconcat(ret, " ");
			ret = my_strconcat(ret, message);
			ret = my_strconcat(ret, "\n");
			return ret;
		}
	}
	else if (my_strncmp(check, "/", 1) == 0)
	{
		ret = "Error: invalid command\n";
		/* if invalid, tell client */
		if (write(fd, ret, my_strlen(ret)) < 0)
			perror("write error"), exit(EXIT_FAILURE);
		
		return NULL;
	}
	else
	{
		/* normal message */
		ret = my_strconcat(ret, ": ");
		ret = my_strconcat(ret, message);
		ret = my_strconcat(ret, "\n");
		return ret;
	}
}
