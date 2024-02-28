#include "game_flow.h"
#include "random_pos.h"
#include "game_figure.h"
#include "astroid.h"
#include "player.h"

#include <algorithm>
#include <ncurses.h>

bool CheckBoundary(int y, int x, int Ymax, int Xmax)
{
  if (((x - 2) < 0) || ((x + 2) >= Xmax))
    return false;
  if ((y < 0) || (y >= Ymax))
    return false;
  return true;
}

bool UpdatePlayer(Player* aPlayer, int y, int x, int Ymax, int Xmax)
{
  bool IsOK = CheckBoundary(y, x, Ymax, Xmax);
  if (IsOK) {
    aPlayer->SetPos(y, x);
    aPlayer->EraseOldPos();
    aPlayer->DrawBlock();
  }
  refresh();
  return IsOK;
}

bool IsCollission(Player const* aPlayer, std::vector<std::unique_ptr<GameFigure>> const& aAstroids)
{

  for (auto & aAstroid : aAstroids) {
    if (aPlayer->mCurrent.x == aAstroid->mCurrent.x && aPlayer->mCurrent.y == aAstroid->mCurrent.y)
      return true;
  }

  for (auto AddPos : aPlayer->mAdditional) {
    for (auto & aAstroid : aAstroids) {
      if (AddPos.x == aAstroid->mCurrent.x && AddPos.y == aAstroid->mCurrent.y)
        return true;
    }
  }

  return false;
}

void RemoveAstroids(std::vector<std::unique_ptr<GameFigure>>& aAstroids, int h, int& FigSurvive) {
  auto Before = aAstroids.size();
  aAstroids.erase(std::remove_if( aAstroids.begin(),
                                  aAstroids.end(),
  [h](std::unique_ptr<GameFigure>& aAstroid) { return aAstroid->mCurrent.y > h; }),
  aAstroids.end());
  auto After = aAstroids.size();
  FigSurvive += Before - After;

}

void AddAstroids(std::vector<std::unique_ptr<GameFigure>>& aAstroids, int w, int FigNumber) {
  for (int i = 0; i < FigNumber; ++i)
    aAstroids.emplace_back(std::make_unique<Astroid>(0, GetRandomStartPos(0, w)));
  refresh();
}