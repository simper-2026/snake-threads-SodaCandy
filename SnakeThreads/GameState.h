#pragma once
#include "Point.h"
class GameState
{
private:
	int boardSize;
public:
	GameState();
	Point player;
	int GetBoardSize();

};

