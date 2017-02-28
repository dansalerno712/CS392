#include "my.h"

char *my_strnconcat(char *a, char *b, int n)
{
	char *res;
	int totalLength;
	if (a != NULL && b != NULL)
	{
		if (n <= 0)
		{
			return my_strdup(a);
		}
		totalLength = n > my_strlen(b) ? my_strlen(a) + my_strlen(b) :
					 my_strlen(a) + n;
		res = (char*)malloc(totalLength + 1);
		my_strcpy(res, a); /* copy a into res */
		my_strncpy(res + my_strlen(a), b, n); /* copy b into res, starting from end of a to n chars */
		return res;
	}
	else
	{
		if (a == NULL && b == NULL)
		{
			return NULL;
		}
		else if (b == NULL)
		{
			return my_strdup(a);
		}
		else
		{
			totalLength = n > my_strlen(b) ? my_strlen(b) : n;
			res = (char*)malloc(n + 1);
			res = my_strncpy(res, b, n);
			return res;
		}
	}
}
