#pragma once

#include "game_figure.h"

struct Astroid : GameFigure
{
  Astroid(int y, int x): GameFigure(y, x) {}
};


void DrawAstroid				(int y, int x);

void EraseOldAstroidPos	(int y, int x);

