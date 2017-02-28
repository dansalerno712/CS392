#include "minitalk.h"

void get_client_pid(int signal)
{
	static pid_t pid = 0; /* hold pid as it is built */
	static int count = 0; /* keeps track of number of bits seen so far */
	/* translates signals to bits */
	pid = pid << 1;
       	if (signal == SIGUSR1)
       	{
       		pid = pid | 1;
       	}
       	else
       	{
       		pid = pid | 0;
       	}
       	/* shifts pid and increments count*/
       	count++;
	/* if we've seen the whole pid, set gl_clientpid to that pid and reset vars */
	if (count == 8 * sizeof(pid_t))
       	{
		gl_clientpid = pid;
		pid = 0;
		count = 0;
	}
}

		     
