#include "my.h"

char *my_vect2str(char **x)
{
	if (x != NULL && x[0] != NULL)
	{
		int totalLength, pos, numWords, i, k;
		char * res;
		pos = 0;
		numWords = 0;
		totalLength = 0;
		/* counts length and words */
		while(x[pos] != NULL)
		{
			totalLength += my_strlen(x[pos]);
			numWords++;
			pos++;
		}
		/*allocate for spaces as well */
		res = (char*)malloc(totalLength + 1 + numWords - 1);
		if (totalLength == 0)
		{
			res[0] = '\0';
			return res;
		}
		pos = 0; /* pposition in vect */
		k = 0; /*position in res */
		/* loop through vector */
		while(x[pos] != NULL)
		{
			i = 0; /* positions in current word */
			/* loop through and copy each string in vector */
			while (1)
			{
				if(x[pos][i] != '\0')
				{
					res[k] = x[pos][i];
					k++;
					i++;
				}
				else
				{
					/* add space */
					res[k] = ' ';
					k++;
					break;
				}
			}
			pos++;
		}
		/* remove unecessary last space and replace with '\0' */
		res[--k] = '\0';
		return res;
	}
	else
	{
		return NULL;
	}
}
