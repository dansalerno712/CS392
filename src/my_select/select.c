#include "my_select.h"

int main(int argc, char **argv)
{
	int i;
	int max_length = 0;
	int ch, small_flag;
	
	if (argc < 2)
	{
		my_str("Usage: ./my_select [stuff you want to select from]\n");
		exit(0);
	}
	/* init screen with raw, keypad on, and no echo */
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(0);
	/* get initialize */
	selected = (int *)malloc(sizeof(int) * (argc - 1));
	mrow = mcol = crow = ccol = lrow = lcol = 0;
	small_flag = 0;
	ch = 0;
	/* find longest string */
	for (i = 1; argv[i] != NULL; i++)
	{
		if (my_strlen(argv[i]) >= max_length)
		{
			max_length = my_strlen(argv[i]);
		}
	}
	/* add 1 for a space */
	max_length++;
	/*initialize selected */
	for (i = 0; i < argc - 1; i++)
		selected[i] = 0;
	/* init screen */
        small_flag = init_scr(argv, max_length);
	/* if displaying files, make first underlined */
	if (small_flag == 0)
	{
		attron(A_UNDERLINE);
		addstr(argv[1]);
		attroff(A_UNDERLINE);
	}
	move(0, 0);
	
	while (1)
	{
		ch = getch();
		/* escape quits */
		if (ch == KEY_RESIZE)
		{
			/* reinit screen */
			small_flag = init_scr(argv, max_length);
			/* if displaying files, make first underlined and highlighted if needed*/
			if (small_flag == 0)
			{
				if (selected[crow + (ccol / max_length) * mrow] == 1)
					attron(A_UNDERLINE | A_STANDOUT);
				else
					attron(A_UNDERLINE);
				addstr(argv[1]);
				attroff(A_UNDERLINE);
				if (selected[crow + (ccol / max_length) * mrow] == 1)
					attroff(A_STANDOUT);
			}
			move(0, 0);
		}
		else if (ch == 27)
		{
			endwin();
			exit(0);
		}
		/* enter exits loop for output */
		else if (ch == KEY_ENTER || ch == '\n')
		{
			break;
		}
		/* space */
		else if (ch == ' ')
		{
			/* toggle selected */
			if (selected[crow + (ccol / max_length) * mrow] == 1)
			{
				selected[crow + (ccol / max_length) * mrow] = 0;
				/* remove highlight and replace with underline */
				attron(A_UNDERLINE);
				addstr(argv[1 + crow + (ccol / max_length) * mrow]);
				attroff(A_UNDERLINE);
				move(crow, ccol);
			}
			else
			{
				selected[crow + (ccol / max_length) * mrow] = 1;
				move_down(argv, max_length);
			}
		}
		else if (ch == KEY_LEFT)
		{
			move_left(argv, max_length);
		}
		else if (ch == KEY_RIGHT)
		{
			move_right(argv, max_length);
		}
		else if (ch == KEY_DOWN)
		{
			move_down(argv, max_length);
		}
		else if (ch == KEY_UP)
		{
			move_up(argv, max_length);
		}
		refresh();
	}
				
	endwin();
	/* output selected files */
	for (i = 0; i < argc - 1; i++)
	{
		if (selected[i] != 0)
		{
			my_str(argv[i + 1]);
			my_char(' ');
		}
	}
	my_char('\n');
	

	return 0;
}
