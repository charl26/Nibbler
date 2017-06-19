#include "CoreGame.hpp"
#include "snake.hpp"

CoreGame *game = new CoreGame();

void genStartingSnake(const std::vector<int> &start) {
	game->addSnakeSegment(start, true);
	while (game->getPlayer().size() < 5) {
		game->addSnakeSegment(start, false);
	}
}

void startGame() {
	std::cout << "Please Enter Starting GUI"
	          << std::endl << ": 1 = SDL"
	          << std::endl << ": 2 = SFML"
	          << std::endl << ": 3 = GLFW"
	          << std::endl;
	int GUI;
	std::cin >> std::ws >> GUI;
	std::vector<int> start = {game->getWindowHeight() / 2, game->getWindowWidth() / 2};
	genStartingSnake(start);
	switch (GUI) {
		case 1: {
			std::cout << "Starting GUI SDL" << std::endl;
			//TODO add start up for GUI 1
			break;
		}
		case 2: {
			std::cout << "Starting GUI SFML" << std::endl;
			//TODO add start up for GUI 2
			break;
		}
		case 3: {
			std::cout << "Starting GUI GLFW" << std::endl;
			//TODO add start up for GUI 3
			break;
		}
		default: {
			std::cout << "ERROR: Invalid input" << std::endl;
			startGame();
		}
	}
}

int main(int argc, char **argv) {
	if (argc == 3) {
		game->setWindowWidth(std::atoi(argv[1]));
		game->setWindowHeight(std::atoi(argv[2]));
		if (0 != game->getWindowWidth() || 0 != game->getWindowHeight()) {
			if (game->getWindowWidth() >= MinWindow && game->getWindowWidth() <= MaxWindow) {
				if (game->getWindowHeight() >= MinWindow && game->getWindowHeight() <= MaxWindow) {
					startGame();
				} else {
					std::cout << "ERROR : Window Height is incorrect." << std::endl;
				}
			} else {
				std::cout << "ERROR : Window Width is incorrect." << std::endl;
			}
		} else {
			std::cout << "ERROR : Window arguments are incorrect." << std::endl;
		}
	} else {
		std::cout << "ERROR : Incorrect amount of arguments." << std::endl;
	}
	return 0;
}