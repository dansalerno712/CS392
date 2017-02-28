#include "myminishell.h"

void my_execvp(char *program, char **argv)
{
	if (program != NULL && argv != NULL)
	{
		if (execvp(program, argv) == -1)
		{
			perror("execvp error");
			/* learned about perror, so this is useless
			if (errno == E2BIG)
				my_str("argv too large");
			else if (errno == EACCES)
				my_str("you dont have the permission to run this file");
			else if (errno == EFAULT)
				my_str("file outside your accessible addres space");
			else if (errno == EINVAL)
				my_str("ELF tried to name multiple interpretors");
			else if (errno == EIO)
				my_str("I/O error");
			else if (errno == EISDIR)
				my_str("ELF interpretor was a directory");
			else if (errno == ELIBBAD)
				my_str("Unrecognized ELF format");
			else if (errno == ELOOP)
				my_str("too many symbolic links");
			else if (errno == EMFILE)
				my_str("max number of files already open in process");
			else if (errno == ENAMETOOLONG)
				my_str("name too long");
			else if (errno == ENFILE)
				my_str("system limit of open files has been reached");
			else if (errno == ENOENT)
				my_str("program does not exist");
			else if (errno == ENOEXEC)
				my_str("executable format error");
			else if (errno == ENOMEM)
				my_str("not enough kernel memory");
			else if (errno == ENOTDIR)
				my_str("component of path is not a directory");
			else if (errno == EPERM)
				my_str("incorrect permissions");
			else if (errno == ETXTBSY)
				my_str("executable open for writing");
			else
				my_str("unknown error");
				
				my_char('\n'); */
		}
	}
}
