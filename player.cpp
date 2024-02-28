#include "player.h"
#include <ncurses.h>

void Player::EraseOldPos()
{
  mvwaddch(stdscr, mOld.y, mOld.x + 2, ' ');
  mvwaddch(stdscr, mOld.y, mOld.x + 1, ' ');
  mvwaddch(stdscr, mOld.y, mOld.x, ' ');
  mvwaddch(stdscr, mOld.y, mOld.x - 1, ' ');
  mvwaddch(stdscr, mOld.y, mOld.x - 2, ' ');
}

void Player::SetPos(int ay, int ax)
{
  mOld.y = mCurrent.y;
  mOld.x = mCurrent.x;

  mCurrent.y = ay;
  mCurrent.x = ax;

  mAdditional.clear();

  mAdditional.push_back(Position{mCurrent.y, mCurrent.x + 2});
  mAdditional.push_back(Position{mCurrent.y, mCurrent.x + 1});
  mAdditional.push_back(Position{mCurrent.y, mCurrent.x - 1});
  mAdditional.push_back(Position{mCurrent.y, mCurrent.x - 2});
  refresh();
}

void Player::DrawBlock()
{
  mvwaddch(stdscr, mCurrent.y, mCurrent.x,   (char)219);
  for (auto AddPos : mAdditional)
    mvwaddch(stdscr, AddPos.y, AddPos.x, (char)219);

  refresh();
};