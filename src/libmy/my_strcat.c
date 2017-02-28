#include "my.h"

char *my_strcat(char *a, char *b)
{
	if (a != NULL && b != NULL)
	{
		int i, j;
		i = 0, j = 0;
		/* finds end of a */
		while(a[i] != '\0')
		{
			i++;
		}
		/* copies b to end of a */
		while(b[j] != '\0')
		{
			a[i] = b[j];
			i++;
			j++;
		}
		a[i] = '\0';
		return a;
	}
	else
	{
		return a;
		/* return a?
		if a is null, return null ptr, which is a
		if b is null, nothing gets added to the string, so return a unchanged
		*/
	}
}
