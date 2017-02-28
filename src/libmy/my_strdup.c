#include "my.h"

char *my_strdup(char *a)
{
	if (a != NULL)
	{
		char *res = (char*)malloc(my_strlen(a) + 1);
		char *src = a;
		char *dest = res;
		
		while(1)
		{
			if (*src == '\0')
			{
				break;
			}
			*dest = *src;
			src++;
			dest++;
		}
		*dest = '\0';
		return res;
	}
	else
	{
		return NULL;
	}
}
