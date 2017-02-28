#include "my.h"

char *my_strncpy(char *a, char *b, int n)
{
	if (a != NULL && b != NULL)
	{
		int pos = 0;
		while (pos < n)
		{
			a[pos] = b[pos];
			if (b[pos] == '\0')
			{
				break;
			}
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
