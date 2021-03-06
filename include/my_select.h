#ifndef _MY_SELECT_H_
#define _MY_SELECT_H_
#include <stddef.h>
#include <stdlib.h>
/* I pledge my honor that I have abided by the Stevens Honor System
 * Daniel Salerno
 */

/*
 * my_select
 * io selector thing
 *
 * Author: Dan Salerno
 */

#include "my.h"
#include <stdlib.h>
#include <ncurses.h>

int mrow, mcol, crow, ccol, lrow, lcol;
int *selected;

void move_left(char **, int);
void move_right(char **, int);
void move_down(char **, int);
void move_up(char **, int);
int init_scr(char **, int);

#endif /*_ MY_SELECT_H_ */
