#include "my.h"

char *my_strrindex(char *a, char b)
{
	if (a != NULL)
	{
		int pos = 0;
		char *res = NULL;
		while (1)
		{
			if (a[pos] == b)
			{
				res = &a[pos];
			}
			if (a[pos] == '\0')
			{
				break;
			}
			pos++;
		}
		return res;
	}
	else
	{
		return NULL;
	}
}
