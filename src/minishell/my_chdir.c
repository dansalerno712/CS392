#include "myminishell.h"

void my_chdir(char *path)
{
	if (path != NULL)
	{
		if (chdir(path) == -1)
		{
			perror("cd error");
		    
			/* Learned about perror so this is useless
			if (errno == EACCES)
				my_str("permission denied");
			else if (errno == EFAULT)
				my_str("path outside accessible address space");
			else if (errno == EIO)
				my_str("an I/O error ocurred");
			else if (errno == ELOOP)
				my_str("too many symolic links");
			else if (errno == ENAMETOOLONG)
				my_str("path is too long");
			else if (errno == ENOENT)
				my_str("path doesn't exist");
			else if (errno == ENOMEM)
				my_str("not enough kernel memory");
			else if (errno == ENOTDIR)
				my_str("path isn't a directory");
			else
				my_str("unknown error");
			*/	

		}
	}
}
