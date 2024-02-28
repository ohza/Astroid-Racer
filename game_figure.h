#pragma once

#include "position.h"

struct GameFigure
{
  GameFigure(int y, int x) {
    mCurrent.y = y;
    mCurrent.x = x;
    mOld.x = x;
    mOld.y = y;
  }
  virtual void SetPos(int ay, int ax);

  virtual ~GameFigure() = default;
  Position mCurrent;
  Position mOld;
};