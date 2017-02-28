#include "minitalk.h"

int main(int argc, char **argv)
{
	pid_t serverpid;
	char *message;
	/* setup signals for USR1 and ALRM */
	signal(SIGUSR1, ack);
	signal(SIGALRM, sig_alarm);
	signal(SIGUSR2, client_quit);
	/* check usage */
	if (argc >= 3)
	{
		/* get server pid as int */
		serverpid = my_atoi(argv[1]);
		send_pid(getpid(), serverpid);
		/* set alarm to time out in5 seconds if no ack received from server */
		alarm(5);
		if (gl_ack == 0)
		{
			pause();
		}
		alarm(0);
		/* send message */
		message = argv[2];
		while (message != NULL && *message != '\0')
		{
			send_char(*message, serverpid);
			message++;
		}
		/* make sure to send \0 to end communication */
		send_char('\0', serverpid);
	}
	else
	{
		my_str("usage: ./client serverpid singlestring [other string that will be ignored]\n");
		exit(0);
	}
	return 0;
}
