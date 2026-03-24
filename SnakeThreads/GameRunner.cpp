#include "GameRunner.h"
#include <thread>
#include <chrono>

using namespace std;

GameRunner::GameRunner()
{
	playerDirection = Direction::RIGHT;
	isRunning = true;

}

void GameRunner::Tick()
{

	//cout << playerDirection << endl;

	switch (playerDirection)
	{
	case Direction::UP:
		state.player.X--;
		break;
	case Direction::DOWN:
		state.player.X++;
		break;
	case Direction::LEFT:
		state.player.Y--;
		break;
	case Direction::RIGHT:
		state.player.Y++;
		break;

	case Direction::NONE:
	default:

		break;
	}
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
	return state.player;
}
