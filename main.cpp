#include "random_pos.h"
#include "position.h"
#include "game_figure.h"
#include "astroid.h"
#include "player.h"
#include "game_flow.h"

#include <ncurses.h>
#include <unistd.h>

#include <iostream>
#include <memory>
#include <vector>
//#include <algorithm>


int main(int argc, char* argv[])
{
  initscr();
  keypad(stdscr, TRUE);
  cbreak();
  noecho();
  int h, w;
  getmaxyx(stdscr, h, w);

  int x, y;
  x = w / 2;
  y = h / 2;
  move(x, y);

  refresh();

  nodelay(stdscr, TRUE);

  unsigned long long  MooveCount = 0;
  int                 FigSurvive = 0;

  curs_set(0); // Have no blinking cursor;
  int ch;

  std::vector<std::unique_ptr<GameFigure>> GameFigs;
  GameFigs.emplace_back(std::make_unique<Astroid>(0, GetRandomStartPos(0, w)));

  Player tplayer(y, x);

  UpdatePlayer(&tplayer, y, x, h, w);

  int GameLevel   = 30;
  int LevelChange = 100;
  bool IsPause    = false;

  while (1)  {

    if (FigSurvive >= 1000) {
      printw("YES YOU MADE IT!!!");
      refresh();
      sleep(5);
      break;
    }

    if ((ch = getch()) != ERR) {
      if      (ch == KEY_DOWN   && !IsPause)   {y++; if (!UpdatePlayer(&tplayer, y, x, h, w)) y--;}
      else if (ch == KEY_UP     && !IsPause)   {y--; if (!UpdatePlayer(&tplayer, y, x, h, w)) y++;}
      else if (ch == KEY_LEFT   && !IsPause)   {x--; if (!UpdatePlayer(&tplayer, y, x, h, w)) x++;}
      else if (ch == KEY_RIGHT  && !IsPause)   {x++; if (!UpdatePlayer(&tplayer, y, x, h, w)) x--;}
      else if (ch == 112) { IsPause = !IsPause; }               //p-key pause
      else if (ch == 121 && GameLevel > 5) { GameLevel -= 5; }  //x-key slower
      else if (ch == 120 && GameLevel < 25) { GameLevel += 5; } //y-key faster
    }

    if (!IsPause) {

      if ((FigSurvive > LevelChange) && (GameLevel > 5)) {
        GameLevel   -= 5;
        LevelChange += 100;
      }

      if (MooveCount % GameLevel == 0) {
        if (MooveCount % 50 == 0)
          AddAstroids(GameFigs, w, 2);
        for (auto & aFig : GameFigs) {
          aFig->SetPos(aFig->mCurrent.y + 1, aFig->mCurrent.x);
          EraseOldAstroidPos(aFig->mOld.y, aFig->mOld.x);
          DrawAstroid(aFig->mCurrent.y, aFig->mCurrent.x);
        }
      }

      auto IsColl = IsCollission(&tplayer, GameFigs);
      if (IsColl) {
        printw("You survived: %d Astroids", FigSurvive);
        refresh();
        sleep(2);
        break;
      }

      MooveCount++;
      usleep(10000);
      RemoveAstroids(GameFigs, h, FigSurvive);
    }
  }
  endwin();
  return 0;
}
