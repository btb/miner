/*
 *
 * Library functions for printing to terminal.
 *
 */

#include <stdarg.h>
#define NCURSES_ENABLE_STDBOOL_H 0
#include <curses.h>

#include "mono.h"


#define MAX_NUM_WINDOWS 32

static WINDOW *Window[MAX_NUM_WINDOWS];

void mputc(int n, char c)
{
	if (!Window[n]) return;

   waddch(Window[n], c);

   wrefresh(Window[n]);
}

void mputc_at(int n, int row, int col, char c)
{
	if (!Window[n]) return;

   wmove(Window[n], row, col);
	mputc(n, c);

   wrefresh(Window[n]);
}

void msetcursor(int row, int col)
{
   move(row, col);

   refresh();
}

void _mprintf(int n, char * format, ...)
{
	va_list args;

	if (!Window[n]) return;

	va_start(args, format);
	vw_printw(Window[n], format, args);
   va_end(args);

   wrefresh(Window[n]);
}

void _mprintf_at(int n, int row, int col, char *format, ...)
{
   va_list args;

	if (!Window[n]) return;

   wmove(Window[n], row, col);

   va_start(args, format);
   vw_printw(Window[n], format, args);
   va_end(args);

   wrefresh(Window[n]);
}

void mclear(int n)
{
	if (!Window[n]) return;

   wclear(Window[n]);

   wrefresh(Window[n]);
}

void mclose(int n)
{
	if (!Window[n]) return;

   if (n) {
      WINDOW *parent;

      parent = wgetparent(Window[n]);
      delwin(Window[n]);
      delwin(parent);
      refresh();

      return;
   }

   endwin();
}

void mrefresh(int n)
{
	if (!Window[n]) return;

   wrefresh(Window[n]);
}

void mopen(int n, int row, int col, int width, int height, char *title)
{
   WINDOW *parent;

   if (Window[n]) mclose(n);

   parent = newwin(height+2, width+2, row-1, col-1);
   box(parent, 0, 0);
   mvwaddstr(parent, 0, 1, title);

   Window[n] = derwin(parent, height, width, 1, 1);

   wrefresh(parent);
}

int minit(void)
{
	int n;
	static int initialized=0;

	if (initialized)
		return 1;

	initialized = 1;

   initscr();

   Window[0] = stdscr;

	mclear(0);

	for (n = 1; n < MAX_NUM_WINDOWS; n++) {
      Window[n] = NULL;
	}

   refresh();

	return -1; // everything ok
}
