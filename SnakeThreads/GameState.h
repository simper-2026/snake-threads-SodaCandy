#pragma once
#include "Point.h"
class GameState
{
private:
	int boardSize;
public:
	GameState();
	GameState(const GameState& other);
	Point player;
	int GetBoardSize();

};

