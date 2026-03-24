#include "GameState.h"

GameState::GameState()
{
    player = { 10, 0 };
    boardSize = 20;
}

int GameState::GetBoardSize()
{
    return boardSize;
}
