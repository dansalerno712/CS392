#include "my.h"

int my_strlen(char *s)
{
	if (s != NULL)
	{
		int counter = 0;
		while (1)
		{
			if (s[counter] == '\0')
			{
				return counter;
			}
			else
			{
				counter++;
			}
		}
	}
	else
	{
		return -1;
	}
}
