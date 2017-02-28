#include "my_select.h"

void move_right(char **argv, int max_length)
{
	/* remove underline */
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attron(A_STANDOUT);
	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attroff(A_STANDOUT);
	/* move cursor */
	if ((ccol + max_length) > lcol)
		crow = lrow;
	else
		ccol += max_length;

	if (ccol == lcol && crow > lrow)
		crow = lrow;

	move(crow, ccol);
	/* underline */
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attron(A_UNDERLINE | A_STANDOUT);
	else
		attron(A_UNDERLINE);
	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	attroff(A_UNDERLINE);
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attroff(A_STANDOUT);
	/* reset cursor */
	move(crow, ccol);
}
