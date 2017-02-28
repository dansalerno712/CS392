#include "my.h"

int my_atoi(char *s)
{
	if (s != NULL)
	{
		int pos, sign, res;
		pos = 0;
		sign = 1;
		res = 0;
		/* loops through until it finds a number
		 * but also keeps track of any hit - 
		 * if it hits end of string, breaks */
		while(s[pos] > '9' || s[pos] < '0')
		{
			if (s[pos] == '-')
			{
				sign *= -1;
			}
			if (s[pos] == '\0')
			{
				break;
			}
			pos++;
		}
		/* calculates int when we have reached the numeric part of string */
		while(s[pos] <= '9' && s[pos] >= '0')
		{
			res = res * 10 + s[pos] - '0';
			pos++;
		}
		return res * sign;
	}
	else
	{
		return 0;
	}
}
