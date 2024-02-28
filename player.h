#pragma once

#include "game_figure.h"
#include <vector>

struct Player : GameFigure
{
  Player(int y, int x): GameFigure(y, x) {
    mAdditional.push_back(Position{mCurrent.y, mCurrent.x + 2});
    mAdditional.push_back(Position{mCurrent.y, mCurrent.x + 1});
    mAdditional.push_back(Position{mCurrent.y, mCurrent.x - 1});
    mAdditional.push_back(Position{mCurrent.y, mCurrent.x - 2});
  }
  void EraseOldPos();
  void DrawBlock	();
  void SetPos			(int ay, int ax) override;

  std::vector<Position> mAdditional;
};