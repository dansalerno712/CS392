#include "my.h"

char *my_strconcat(char *a, char *b)
{
	if (a != NULL && b != NULL)
	{
		char *res = (char*)malloc(my_strlen(a) + my_strlen(b) + 1);
		my_strcpy(res, a); /* copy a into res */
		my_strcat(res, b); /* stick b on end */
		return res;
	}
	else
	{
		if (a == NULL && b == NULL)
		{
			return NULL;
		}
		else if (a == NULL)
		{
			return my_strdup(b);
		}
		else
		{
			return my_strdup(a);
		}
	}
}
