#include "minitalk.h"

void sig_alarm()
{
	my_str("\nError: Connection timed out\n");
	exit(EXIT_FAILURE);
}
