#include "my.h"
int my_find(char *s, char c)
{
	if (s != NULL)
	{
		int pos = 0;
		while(1)
		{
			char test = s[pos];
			if (test == c)
			{
				return pos;
			}
			else if (test == '\0')
			{
				return -1;
			}
			pos++;
		}
	}
	else
	{
		return -1;
	}
}

