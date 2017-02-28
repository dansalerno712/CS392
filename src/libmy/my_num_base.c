#include "my.h"

void my_num_base(int i, char *s)
{
	if (s != NULL)
	{
		unsigned int maxPowBase, j, uinti, firstDigit;
		int length = my_strlen(s);
		if (length != 0)
		{
			uinti = i < 0 ? -((unsigned int)(i)) : (unsigned int)(i);
			if (i < 0)
			{
				my_char('-');
			}
			if (length == 1)
			{
				for (; uinti > 0; uinti--)
				{
					my_char(s[0]);
				}
			}
			else
			{
				maxPowBase = 1, j = uinti;
				while (j > (length - 1))
				{
					maxPowBase *= length;
					j /= length;
				}
				while (maxPowBase != 0)
				{
					firstDigit = uinti / maxPowBase;
					my_char(s[firstDigit]);
					uinti -= firstDigit * maxPowBase;
					maxPowBase /= length;
				}
			}
		}
		else
		{
			my_str("Error: Empty symbol input");
		}
	}
	else
	{
		my_str("Error: Null symbol input");
	}
}
