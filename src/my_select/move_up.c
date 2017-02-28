#include "my_select.h"

void move_up(char **argv, int max_length)
{
	/* remove underline and highlight if needed */
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attron(A_STANDOUT);
	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attroff(A_STANDOUT);

	/* move */
	if (crow == 0)
	{
		if (ccol == 0)
		{
			crow = lrow;
			ccol = lcol;
		}
		else
		{
			ccol -= max_length;
			crow = mrow - 1;
		}
		
	}
	else
		crow--;
	move(crow, ccol);
	/* underline / highlight */
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attron(A_UNDERLINE | A_STANDOUT);
	else
		attron(A_UNDERLINE);

	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	attroff(A_UNDERLINE);
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attroff(A_STANDOUT);

	move(crow, ccol);
	
}
