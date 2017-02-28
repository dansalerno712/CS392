#include "my.h"

char *my_strcpy(char *a, char *b)
{
	if (a != NULL && b != NULL)
	{
		int pos = 0;
		while(1)
		{
			if (b[pos] == '\0')
			{
				break;
			}
			a[pos] = b[pos];
			pos++;
		}
		a[pos] = '\0';
		return a;
	}
	else
	{
		return a;
	}
}
