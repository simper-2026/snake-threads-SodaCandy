#include "GameRunner.h"
#include <thread>
#include <chrono>

using namespace std;

void GameRunner::SwapBuffer()
{
	GameState* temp = current;
	current = next;
	next = temp;
}

GameRunner::GameRunner()
{
	playerDirection = Direction::RIGHT;
	isRunning = true;
	
	buffer[0] = GameState{};
	buffer[1] = GameState{};

	current = &buffer[0];
	next = &buffer[1];
}

void GameRunner::Tick()
{

	//cout << playerDirection << endl;
	*next = *current;

	switch (playerDirection)
	{
	case Direction::UP:
		next->player.X--;
		break;
	case Direction::DOWN:
		next->player.X++;
		break;
	case Direction::LEFT:
		next->player.Y--;
		break;
	case Direction::RIGHT:
		next->player.Y++;
		break;

	case Direction::NONE:
	default:

		break;
	}
	SwapBuffer();
}

void GameRunner::SetDirection(Direction d)
{
	playerDirection = d;
}

void GameRunner::Run()
{
	while (isRunning) {
		Tick();
		this_thread::sleep_for(chrono::milliseconds(200));
	}
}

void GameRunner::Quit()
{
	isRunning = false;
}

bool GameRunner::IsRunning()
{
	return isRunning;
}

GameState* GameRunner::GetBuffer()
{
	return current;
}
