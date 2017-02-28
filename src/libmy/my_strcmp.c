#include "my.h"

int my_strcmp(char *a, char *b)
{
	if (a != NULL && b != NULL)
	{
		/* loop until unequal chars */
		while (*a == *b)
		{
			if (*a == '\0' || *b =='\0')
			{
				break;
			}
			else
			{
				a++;
				b++;
			}
		}
		/* lexographically sory */
		return *a - *b;
	}
	else
	{
		if (a == NULL && b == NULL)
		{
			return 0;
		}
		else if (a == NULL)
		{
			return -1;
		}
		else
		{
			return 1;
		}
	}
}
