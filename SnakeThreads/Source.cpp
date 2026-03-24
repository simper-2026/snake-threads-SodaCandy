#include "KeyboardInput.h"
#include "GameRunner.h"
#include <thread>
#include <chrono>
#include "ConsoleDisplay.h"

using namespace std;


int main() {

	GameRunner game;
	KeyboardInput input(&game);
	ConsoleDisplay console(&game);

	thread inputThread(&KeyboardInput::Run, &input);
	thread gameThread(&GameRunner::Run, &game);
	thread displayThread(&ConsoleDisplay::Run, &console);

	inputThread.join();
	gameThread.join();
	displayThread.join();
}