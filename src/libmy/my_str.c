#include "my.h"

void my_str(char *s)
{
	if (s != NULL) 
	{
		int pos = 0;
		while (s[pos] != '\0')
		{
			my_char(s[pos]);
			pos++;
		}
	}
}
