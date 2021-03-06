#include "my_select.h"

void move_left(char **argv, int max_length)
{
	/* remove underline */
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attron(A_STANDOUT);
	addstr(argv[1 + crow + (ccol / max_length) * mrow]);
	if (selected[crow + (ccol / max_length) * mrow] == 1)
		attroff(A_STANDOUT);
	/* move cursor */
	if (ccol == 0)
		crow = 0;
	else
		ccol -= max_length;
	move(crow, ccol);
	/* add underline */
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
