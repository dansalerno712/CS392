#ifndef _MYMINISHELL_H_
#define _MYMKNISHELL_H_

#include "my.h"
#include <unistd.h>
#include <errno.h>
#include <stdio.h> /* for perror */

void my_chdir(char*);
void my_execvp(char*, char**);

#endif
