#pragma once
#include "game_figure.h"
#include "astroid.h"
#include "player.h"

#include <vector>
#include <memory>

bool CheckBoundary 	(int y, int x, int Ymax, int Xmax);

bool UpdatePlayer  	(Player* aPlayer, int y, int x, int Ymax, int Xmax);

bool IsCollission  	(Player const* aPlayer, std::vector<std::unique_ptr<GameFigure>> const& aAstroids);

void RemoveAstroids	(std::vector<std::unique_ptr<GameFigure>>& aAstroids, int h, int& FigSurvive); 

void AddAstroids		(std::vector<std::unique_ptr<GameFigure>>& aAstroids, int w, int FigNumber); 