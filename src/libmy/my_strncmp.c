#include "my.h"

int my_strncmp(char *a, char *b, int n)
{
	if (a != NULL && b != NULL)
	{
		int counter = 1;
		if (n <= 0)
		{
			return 0;
		}
		/* loop until unequal or reached n */
		while(*a == *b && counter < n)
		{
			if (*a == '\0' || *b == '\0' || counter >= n)
			{
				break;
			}
			else
			{
				a++;
				b++;
				counter++;
			}
		}
		/* lexographically sort */
		return *a - *b;
	}
	else
	{
		/* what should i return*/
                if (a == NULL && b == NULL)
                {
                        return 0;
                }
                else if (a == NULL)
                {
                        return -1;
                }
                else
                {
                        return 1;
		}
	}
}
