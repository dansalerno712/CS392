#include "minitalk.h"

void quit()
{
	my_str("\nStopping the server...\n");
	if (kill(gl_clientpid, SIGUSR2) < 0)
	{
		my_str("The client has already exited, so no message needs to be sent\n");
	}
	exit(0);
}
