#include "my.h"

char *my_strindex(char *a, char b)
{
	if (a != NULL)
	{
		int pos = 0;
		while (1)
		{
			if (a[pos] == b)
			{
				return &a[pos];
			}
			else if (a[pos] == '\0')
			{
				return NULL;
			}
			else
			{
				pos++;
			}
		}
	}
	else
	{
		return NULL;
	}
}
