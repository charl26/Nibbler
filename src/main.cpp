#include <dlfcn.h>
#include "CoreGame.hpp"

CoreGame *game = new CoreGame();

void genStartingSnake(const std::vector<int> &start) {
	std::vector<int> pos;

	game->addSnakeSegment(start, true);
	pos = start;
	pos[0]++;

	while (game->getPlayer().size() < 5) {
		game->addSnakeSegment(pos, false);
		pos[0]++;
	}
}

void runGame(void *handle) {

}

void startGame() {
	std::cout << "Please Enter Starting GUI"
	          << std::endl << ": 1 = SDL"
	          << std::endl << ": 2 = SFML"
	          << std::endl << ": 3 = GLFW"
	          << std::endl;
	int GUI;
	void *handle = NULL;
	std::cin >> std::ws >> GUI;
	std::vector<int> start = {game->getWindowHeight() / 2, game->getWindowWidth() / 2};
	genStartingSnake(start);
	game->SpawnFood();
	switch (GUI) {
		case 1: {
			std::cout << "Starting GUI SDL" << std::endl;
			handle = dlopen(SDL2LIB, RTLD_LAZY);
			break;
		}
		case 2: {
			std::cout << "Starting GUI SFML" << std::endl;
			handle = dlopen(SMFLLIB, RTLD_LAZY);
			break;
		}
		case 3: {
			std::cout << "Starting GUI GLFW" << std::endl;
			handle = dlopen(GLFWLIB, RTLD_LAZY);
			break;
		}
		default: {
			std::cout << "ERROR: Invalid input" << std::endl;
			startGame();
		}
	}

	runGame(handle);
}

int main(int argc, char **argv) {
	if (argc == 3) {
        game->setWindowWidth(std::atoi(argv[1]));
        game->setWindowHeight(std::atoi(argv[2]));

        if (game->getWindowWidth() >= MinWindow && game->getWindowWidth() <= MaxWindow &&
            game->getWindowHeight() >= MinWindow && game->getWindowHeight() <= MaxWindow)
            startGame();
        else {
			std::cout << "ERROR: Window size is incorrect." << std::endl;
			return (-1);
		}
    } else {
		std::cout << "ERROR: Invalid number of Arguments" << std::endl;
		return (-1);
	}

	switch (game->getState()) {
		case 1: {
			// TODO: Menu state
		}
		case 2: {
			while (game->getState() == 2)
				game->CheckInput();
		}
		case 3: {
			// TODO: Game over state
		}
		default: {
			game->setState(2); // TODO: Update to 1 - Menu state
		}
	}
	return 0;
}
