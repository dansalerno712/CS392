#include "my.h"

char **my_str2vect(char *x)
{
	if (x != NULL)
	{
		int numStrings, pos, currentWord, start, end;
		char **ret;
		/* counts number of strings to calculate length of return array */
		numStrings = 0;
		pos = 0;
		while (1)
		{
			if (x[pos] == '\0')
			{
				break;
			}
			while (x[pos] == '\t' || x[pos] == '\n' || x[pos] == ' ')
			{
				pos++;
			}
			numStrings++;
			while (x[pos] != '\t' && x[pos] != '\n' && x[pos] != ' ' && x[pos] != '\0')
			{
				pos++;
			}
		}
		if (numStrings == 0)
		{
			ret = (char**)malloc(1);
			ret[0] = NULL;
			return ret;
		}
		else
		{
			/* allocates + 1 to leave room for ending NULL */
			ret = (char**)malloc(numStrings * sizeof(char*) + 1);
		}
		pos = 0;
		currentWord = 0;
		start = 0;
		end = 0;
		/* loops through the string again, skips any space characters
		 * then copies the word into the corresponding array inside vector */
		while (1)
		{
			if (x[start] == '\0')
			{
				break;
			}
			/* finds start of word */
			while(x[start] == '\t' || x[start] == '\n' || x[start] == ' ')
			{
				start++;
			}
			end = start;
			/* finds end of word */
			while (x[end] != '\t' && x[end] != '\n' && x[end] != ' ' && x[end] != '\0')
			{
				end++;
			}
			if (end == start)
			{
				continue;
			}
			ret[currentWord] = (char*)malloc(end - start + 1);
			pos = 0;
			/* copies word */
			for(; start < end; start++)
			{
				ret[currentWord][pos] = x[start];
				pos++;
			}
			ret[currentWord][start] = '\0';
			currentWord++;
		}
		ret[currentWord] = NULL;
		return ret;
	}
	else
	{
		return NULL;
	}
}
