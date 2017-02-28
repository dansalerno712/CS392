#include "minitalk.h"

int main()
{
	/* display server pid */
	int i;
	my_str("The server is currently running at PID ");
	my_int(getpid());
	my_str("\n--------------------------------------------\n");
	/* setup SIGINT signal */
	signal(SIGINT, quit);
	/* loop until ctrl c */
	while (1)
	{
		gl_doneflag = 0;
		/* setup SIGUSR1 and SIGUSR2 */
		signal(SIGUSR1, get_client_pid);
		signal(SIGUSR2, get_client_pid);
		/* pause until pid is collected */
		for (i = 0; i < sizeof(pid_t) * 8; i++)
		{
			pause();
		}
		/* change SIGUSR1 and SIGUSR2 to accept chars */
		signal(SIGUSR1, get_char);
		signal(SIGUSR2, get_char); 
		/* send ack (SIGUSR1) to client that pid has been received */
		if (kill(gl_clientpid, SIGUSR1) < 0)
		{
			perror("Error sending ack to client:");
			exit(EXIT_FAILURE);
		}
		/* keep waiting for bits to print message */
		while (gl_doneflag == 0)
		{
			pause();
		}
		/*print newline and start over */
		my_str("\n-----------------------------------\n");
	}
	return 0;
}
