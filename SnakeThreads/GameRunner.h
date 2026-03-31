#pragma once
#include "Direction.h"
#include <atomic>
#include "Point.h"
#include "GameState.h"


class GameRunner
{
private:
	std::atomic<bool> isRunning;

	std::atomic<Direction> playerDirection;
	GameState buffer[2];
	GameState* current;
	GameState* next;

	void SwapBuffer();
public:
	GameRunner();
	void Tick();
	void SetDirection(Direction d);
	void Run();
	void Quit();
	bool IsRunning();
	GameState* GetBuffer();
};