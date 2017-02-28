#include "my.h"

int my_rfind(char *s, char c)
{
	if (s != NULL)
	{
		int pos = 0;
		int match = -1;
		while(1)
		{
			char test = s[pos];
			if (test == c)
			{
				match = pos;
			}
			if (test == '\0')
			{
				break;
			}
			pos++;
		}
		return match;
	}
	else
	{
		return -1;
	}
}
