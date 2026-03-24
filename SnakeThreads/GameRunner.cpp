#include "GameRunner.h"
#include <thread>
#include <chrono>

using namespace std;

void GameRunner::DrawBoard()
{

}
GameRunner::GameRunner()
{
	playerDirection = Direction::RIGHT;
	player = { 10, 0 };
	isRunning = true;

	
}

void GameRunner::Tick()
{

	//cout << playerDirection << endl;

	switch (playerDirection)
	{
	case Direction::UP:
		player.X--;
		break;
	case Direction::DOWN:
		player.X++;
		break;
	case Direction::LEFT:
		player.Y--;
		break;
	case Direction::RIGHT:
		player.Y++;
		break;

	case Direction::NONE:
	default:

		break;
	}

	DrawBoard();
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

Point GameRunner::GetBuffer()
{
	return player;
}
