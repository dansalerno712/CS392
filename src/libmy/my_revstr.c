#include "my.h"

int my_revstr(char *s)
{
	if (s != NULL) 
	{
		int length = my_strlen(s);
		int temp, i, j;
		for (i = 0, j = length - 1; i < j; i++, j--)
		{
			temp = s[i];
			s[i] = s[j];
			s[j] = temp;
		}
		return length;
	}
	else
	{
		return -1;
	}
}
