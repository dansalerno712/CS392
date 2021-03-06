#include "myminishell.h"
#include <sys/wait.h>

int main(int argc, char **argv)
{
	int bytes_read;
	int pid;
	char *in_buffer;
	char **in_vector;
	int pos;
	char *current_dir;

	in_buffer = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
	current_dir = (char*)malloc(MAX_BUFFER_SIZE * sizeof(char));
	
	while (1)
	{
		my_str("minishell: ");
		if (getcwd(current_dir, 1000) == NULL)
		{
			my_str("Error getting current directory");
		}
		else
		{
			my_str(current_dir);
		}
		my_str(" $ ");
	/* reads from fd 0 (stdin), reads MAX_BUFFER_SIZE chars and stores in in_buffer */
		bytes_read = read(0, in_buffer, MAX_BUFFER_SIZE);
		in_buffer[bytes_read - 1] = '\0'; /* add terminator */
		
		if (bytes_read > 1) /* if user entered something */
		{
			in_vector = my_str2vect(in_buffer);
			/* if cd is command */
			if (my_strcmp(in_vector[0], "cd") == 0)
			{
				if (in_vector[1] == NULL)
				{
					my_str("You forgot the path\n");
					continue;
				}
				else
				{
					my_chdir(in_vector[1]); /* inVector[1] is path */
				}
			}
			else if (my_strcmp(in_vector[0], "exit") == 0) /* user enters exit */
			{
				break;
			}
			else if (in_vector[0] != NULL) /* user entered a program and args */
			{
				if ((pid = fork()) < 0)
				{
					my_str("Error forking for process execution\n");
					exit(EXIT_FAILURE); 
				}
				else if (pid > 0) /* parent should wait until child ends */
				{
					wait(NULL); 
				}
				else
				{ /* in_vector[0] is program, in_vector is argv */
					my_execvp(in_vector[0], in_vector); 
					/* if execvp fails, still end child process */
					exit(EXIT_FAILURE); 
				}
			}
			/* free in_vector */
			pos = 0;
			while (in_vector[pos] != NULL)
			{
				free(in_vector[pos]);
				pos++;
			}
		}
		if (bytes_read < 0)
		{
			my_str("Error reading user input\n");
		}
	}
	/* free everything */
	free(in_buffer);
	free(current_dir);
	pos = 0;
	while (in_vector[pos] != NULL)
	{
		free(in_vector[pos]);
		pos++;
	}
	free(in_vector);
	
	my_str("Exiting minishell. The ride never ends\n");
	return 0;
}
