#include "sockettalk.h"

void send_message(int listener, char *message)
{
	int j;

	for (j = 3; j <= gl_max_fd; j++)
	{
		if (FD_ISSET(j, &gl_master))
		{
			if (j != listener)
			{
				if (write(j, message, my_strlen(message)) < 0)
					perror("write() error"), exit(EXIT_FAILURE);
			}
		}
	}
	
}
