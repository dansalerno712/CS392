#include "my_select.h"

int init_scr(char **argv, int max_length)
{
	int small_flag;
	int i;
	clear();
	getmaxyx(stdscr, mrow, mcol);
	crow = 0;
	ccol = 0;
	small_flag = 0;
	/* print files in columns */
	for (i = 1; argv[i] != NULL; i++)
	{
		/* if row overflow */
		if (crow == mrow)
		{
			/* reset row and increment column */
			crow = 0;
			ccol += max_length;
			/* if cant fint new row */
			if (ccol + my_strlen(argv[i]) >= mcol)
			{
				/* print resize window */
				ccol = 0;
				clear();
				addstr("Resize your window");
				refresh();
				small_flag = 1;
				break;
			}
		}
		/* print string */
		if (selected[crow + (ccol / max_length) * mrow] == 1)
			attron(A_STANDOUT);
		mvaddnstr(crow, ccol, argv[i], max_length - 1);
		if (selected[crow + (ccol / max_length) * mrow] == 1)
			attroff(A_STANDOUT);
		refresh();
		crow++;
	}
	/* store last r/c */
	lrow = crow - 1;
	lcol = ccol;
	/* move to top left */
	move(0, 0);
	crow = 0;
	ccol = 0;
	return small_flag;
}
