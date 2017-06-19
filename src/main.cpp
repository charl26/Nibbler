#include "CoreGame.hpp"
#include "snake.hpp"

int windowWidth;
int windowHeight;
std::list<Snake*> player;

void addSnakeSegment(const std::vector<int> &position) {
	Snake *snakeSegment = new Snake(position, false);
	player.push_back(snakeSegment);
}

void genStartingSnake(const std::vector<int> &start) {
	Snake *snakeHead = new Snake(start, true);
	player.push_back(snakeHead);
	while (player.size() < 5) {
		addSnakeSegment(start);
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
	std::vector<int> start = {windowHeight /2, windowWidth/2};
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
		windowWidth = std::atoi(argv[1]);
		windowHeight = std::atoi(argv[2]);
		if (0 != windowWidth || 0 != windowHeight) {
			if (windowWidth >= MinWindow && windowWidth <= MaxWindow){
				if (windowHeight >= MinWindow && windowHeight <= MaxWindow) {
					startGame();
				}else{
					std::cout << "ERROR : Window Height is incorrect." << std::endl;
				}
			} else{
				std::cout << "ERROR : Window Width is incorrect." << std::endl;
			}
		}else {
			std::cout << "ERROR : Window arguments are incorrect." << std::endl;
		}
	} else {
		std::cout << "ERROR : Incorrect amount of arguments." << std::endl;
	}
	return 0;
}