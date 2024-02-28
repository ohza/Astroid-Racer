#include "game_figure.h"

void GameFigure::SetPos(int ay, int ax)
{
  mOld.y = mCurrent.y;
  mOld.x = mCurrent.x;

  mCurrent.y = ay;
  mCurrent.x = ax;
}