#include "my_select.h"

void move_down(char** argv, int max_length)
{
	/* remove underline/ highlight */
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attron(A_STANDOUT);
	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attroff(A_STANDOUT);

	/* move */
	if (crow == lrow && ccol == lcol)
	{
		crow = 0;
		ccol = 0;
	}
	else if (crow == mrow - 1)
	{
		crow = 0;
		ccol += max_length;
	}
	else
		crow++;
	move(crow, ccol);

	/* underline/highlight */
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
