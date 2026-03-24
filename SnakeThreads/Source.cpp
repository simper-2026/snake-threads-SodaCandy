#include "KeyboardInput.h"
#include "GameRunner.h"
#include <thread>
#include <chrono>

using namespace std;


int main() {

	GameRunner game;
	KeyboardInput input(&game);

	while (true) {

		input.CheckInput();
		game.Tick();

		this_thread::sleep_for(chrono::milliseconds(200));

	}
}