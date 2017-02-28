#include "minitalk.h"

void send_char(char c, pid_t server_pid)
{
	int mask = 0x80; /* mask to get first bit of char */
	int i;
	/* loops through each bit of char (8 bits) */
	for (i = 0; i < 8; i++)
	{
		/* translates to signals */
		if (mask & c)
		{
			if (kill(server_pid, SIGUSR1) < 0)
			{
				perror("Error sending signal to server:");
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) < 0)
			{
				perror("Error sending signal to server:");
			}
		}
		/* shift */
		c = c << 1;
		/* wait until server sends ack */
		pause();
	}
	
}
