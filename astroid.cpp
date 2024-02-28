#include "astroid.h"
#include <ncurses.h>

void EraseOldAstroidPos(int y, int x)
{
  mvwaddch(stdscr, y, x, ' ');
  refresh();
}

void DrawAstroid(int y, int x)
{
  mvwaddch(stdscr, y, x, '*');
  refresh();
}