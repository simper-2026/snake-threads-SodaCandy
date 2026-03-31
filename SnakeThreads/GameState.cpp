#include "GameState.h"

GameState::GameState()
{
    player = { 10, 0 };
    boardSize = 20;
}

GameState::GameState(const GameState& other) 
{
    player = other.player;
    boardSize = other.boardSize;
}

int GameState::GetBoardSize()
{
    return boardSize;
}

