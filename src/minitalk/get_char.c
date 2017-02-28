#include "minitalk.h"

void get_char(int signal)
{
	static char in = 0; /* holds incoming char */
	static int bit_count = 0;
	/* translates signals to bits */
	in = in << 1;
	if (signal == SIGUSR1)
	{
		in = in | 1;
	}
	else
	{
		in = in | 0;
	}
	bit_count++;
	/* if full char is read, print it and end if \0 */
	if (bit_count == 8)
	{
		if (in == '\0')
		{
			gl_doneflag = 1;
		}
		my_char(in);
		/* reset vars */
		in = 0;
		bit_count = 0;
	}
	/* send ack to client */
	if (kill(gl_clientpid, SIGUSR1) < 0)
	{
		perror("Error sending ack to client:");
	}
}
