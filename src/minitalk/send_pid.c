#include "minitalk.h"

void send_pid(pid_t my_pid, pid_t server_pid)
{
	int mask = 1 << (sizeof(pid_t) * 8 - 1); /*mask is a 1 that corresponds to first bit of a pid_t */
	int i;
	/* loop throughall bits of pid_t */
	for (i = 0; i < (sizeof(pid_t) * 8); i++)
	{
		/* translate bit to signal and send*/
		if (my_pid & mask)
		{
			if (kill(server_pid, SIGUSR1) < 0)
			{
				perror("Error sending signal to server");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (kill(server_pid, SIGUSR2) < 0)
			{
				perror("Error sending signal to server");
				exit(EXIT_FAILURE);
			}
		}
		/* shift pid */
		my_pid = my_pid << 1;
		/*sleep so server has time to process */
		usleep(2000);
	}
}
