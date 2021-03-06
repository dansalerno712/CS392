/* I pledge my honor that I have abided by the Stevens Honor System
 * Daniel Salerno
 */
#include "my.h"
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int p_to_c_pipe[2]; /* parent to child pipe */
	int c_to_g_pipe[2]; /* child to grandchild pipe */
	int pid_c; /*child pid */
	int pid_g; /*grandchild pid */
	char *buf;
	int bytes_read;
	
	if (argc < 2) /*show usage statment if they just typed ./pipes */
	{
		my_str("usage: ./pipes arg1 [arg2] [arg3] ...\n");
	}
	else
	{
		buf = argv[1];
		if (buf == NULL)
		{
			buf = my_strdup("NULL");
		}
		/* create/check parent to child pipe */
		if (pipe(p_to_c_pipe) < 0)
		{
			my_str("Error creating parent to child pipe\n");
			exit(EXIT_FAILURE);
		}
		/* fork and create child process */
		if ((pid_c = fork()) < 0)
		{
			my_str("Error forking child process\n");
			exit(EXIT_FAILURE);
		}
		if (pid_c > 0)
		{
			/* close read pipe of p to c*/
			if (close(p_to_c_pipe[0]) < 0)
			{
				my_str("Error closing write pipe of p to c pipe");
			}			
			/* write contents of first argument to pipe to child */
			if (write(p_to_c_pipe[1], buf, MAX_BUFFER_SIZE) < 0)
			{
				my_str("Error writing to pipe by parent process\n");
				exit(EXIT_FAILURE);
			}
     			/* wait for child process to end */
			waitpid(pid_c, NULL, 0);
		}
		else
		{
			/* close write pipe of p to c*/
			if (close(p_to_c_pipe[1]) < 0)
			{
				my_str("Error closing read pipe of p to c pipe");
			}
			/* create child to grandchild pipe */
			if (pipe(c_to_g_pipe) < 0)
			{
				my_str("Error creating child to grandchild pipe\n");
				exit(EXIT_FAILURE);
			}
			/* fork and create grandchile process */
			if ((pid_g = fork()) < 0)
			{
				my_str("Error forking grandchild process\n");
				exit(EXIT_FAILURE);
			}
			else if (pid_g > 0)
			{
				/* read message from parent from pipe */
				bytes_read = read(p_to_c_pipe[0], buf, MAX_BUFFER_SIZE);
				if (bytes_read < 0)
				{
					my_str("Error child failed to read pipe\n");
					exit(EXIT_FAILURE);
				}
				/* close read pipe of c to g*/
				if (close(c_to_g_pipe[0]) < 0)
				{
					my_str("Error closing write pipe of c to g pipe");
				}
				/* write read message to pipe to send to grandchild */
				if (write(c_to_g_pipe[1], buf, MAX_BUFFER_SIZE) < 0)
				{
					my_str("Error writing to pipe by child process\n");
					exit(EXIT_FAILURE);
				}
				/* wait for grandchild process to end */
				waitpid(pid_g, NULL, 0);
			}
			else
			{
				/* close write pipe of c to g*/
				if (close(c_to_g_pipe[1]) < 0)
				{
					my_str("Error closing write pipe of c to g pipe");
				}
				/* read message from child process from pipe */
				bytes_read = read(c_to_g_pipe[0], buf, MAX_BUFFER_SIZE);
				if (bytes_read < 0)
				{
					my_str("Error reading pipe in grandchild process\n");
					exit(EXIT_FAILURE);
				}
				buf[bytes_read - 1] = '\0';
				/*print message */
				my_str(buf);
				my_char('\n');
			}
		}
	}
	return 0;
}
