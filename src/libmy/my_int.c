#include "my.h"

void my_int(int i)
{
	unsigned int maxPow10, j, uinti, firstDigit;
	uinti = i < 0 ? -((unsigned int)(i)) : (unsigned int)(i);
	if (i < 0)
	{
		my_char('-');
	}
	maxPow10 = 1, j = uinti;
	while (j > 9)
	{
		maxPow10 *= 10;
		j /= 10;
	}
	while (maxPow10 != 0)
	{
		firstDigit = uinti / maxPow10;
		my_char(((int)(firstDigit)) + '0');
		uinti -= firstDigit * maxPow10;
		maxPow10 /= 10;
	}
}
