//
// Created by Charl THERON on 2017/06/09.
//

#include "CoreGame.hpp"

int CoreGame::getWindowWidth() const {
	return windowWidth;
}

void CoreGame::setWindowWidth(int windowWidth) {
	CoreGame::windowWidth = windowWidth;
}

int CoreGame::getWindowHeight() const {
	return windowHeight;
}

void CoreGame::setWindowHeight(int windowHeight) {
	CoreGame::windowHeight = windowHeight;
}

const std::list<Food *, std::allocator<Food *>> &CoreGame::getFood() const {
	return food;
}

const std::vector<Snake *> &CoreGame::getPlayer() const {
	return player;
}

void CoreGame::setPlayer(const std::vector<Snake *> &player) {
	CoreGame::player = player;
}

void CoreGame::setFood(const std::list<Food *, std::allocator<Food *>> &food) {
	CoreGame::food = food;
}

CoreGame::CoreGame() {
	CoreGame::setState(2);
	std::cout << "CoreGame Constructor Called" << std::endl;
	srand((unsigned)time(0));
}

void CoreGame::addSnakeSegment(const std::vector<int> &position, bool isHead) {
	Snake *snakeSegment = new Snake(position, isHead, UP);
	player.push_back(snakeSegment);
}

void CoreGame::SpawnFood() {
	if (CoreGame::food.size() < 5) {
		Food *food = new Food(CoreGame::RandomPosition());
		CoreGame::food.push_back(food);
	}
}

std::vector<int> CoreGame::RandomPosition() {
	int x = std::rand() % CoreGame::getWindowWidth();
	int y = std::rand() % CoreGame::getWindowHeight();
	std::vector<int> v = {x , y};

    std::cout << "Food Random X: " << x << std::endl;
    std::cout << "Food Random Y: " << y << std::endl;
	return (v);
}

CoreGame CoreGame::operator=(const CoreGame &rhs) {
	CoreGame::food = rhs.getFood();
	CoreGame::player = rhs.getPlayer();
	CoreGame::windowWidth = rhs.getWindowWidth();
	CoreGame::windowHeight = rhs.getWindowHeight();

	return (*this);
}

CoreGame::CoreGame(const CoreGame &coreGame) {
	CoreGame::operator=(coreGame);
}

int CoreGame::getState() const {
	return state;
}

void CoreGame::setState(int state) {
	CoreGame::state = state;
}

CoreGame::~CoreGame() {}

void CoreGame::CheckInput() {
	struct termios old_tio, new_tio;
	unsigned char key;
	std::vector<int> pos;

	tcgetattr(STDIN_FILENO, &old_tio);
	new_tio=old_tio;
	new_tio.c_lflag &=(~ICANON & ~ECHO);
	tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
	key = (unsigned char)std::getchar();

	pos = player[0]->getPosition();
	if (key == 'w' && player[0]->getDirection() != DOWN) {
		if (player[0]->getPosition()[0] > 0) {
			player[0]->setDirection(UP);
			player[0]->setLastP(player[0]->getPosition());
			pos[0]--;
			player[0]->setPosition(pos);
			std::cout << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position X = " << player[0]->getLastP()[1] << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position Y = " << player[0]->getLastP()[0] << std::endl;
			std::cout << "Player segment " << 0 << " X: " << player[0]->getPosition()[1] << std::endl;
			std::cout << "Player segment " << 0 << " Y: " << player[0]->getPosition()[0] << std::endl;
			Move();
		}
		// TODO:: Game Over If < 0
	}
	if (key == 'a' && player[0]->getDirection() != RIGHT) {
		if (player[0]->getPosition()[1] > 0) {
			player[0]->setDirection(LEFT);
			player[0]->setLastP(player[0]->getPosition());
			pos[1]--;
			player[0]->setPosition(pos);
			std::cout << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position X = " << player[0]->getLastP()[1] << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position Y = " << player[0]->getLastP()[0] << std::endl;
			std::cout << "Player segment " << 0 << " X: " << player[0]->getPosition()[1] << std::endl;
			std::cout << "Player segment " << 0 << " Y: " << player[0]->getPosition()[0] << std::endl;
			Move();
		}
		// TODO:: Game Over If > windowWidth
	}
	if (key == 's' && player[0]->getDirection() != UP) {
		if (player[0]->getPosition()[0] < windowHeight) {
			player[0]->setDirection(DOWN);
			player[0]->setLastP(player[0]->getPosition());
			pos[0]++;
			player[0]->setPosition(pos);
			std::cout << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position X = " << player[0]->getLastP()[1] << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position Y = " << player[0]->getLastP()[0] << std::endl;
			std::cout << "Player segment " << 0 << " X: " << player[0]->getPosition()[1] << std::endl;
			std::cout << "Player segment " << 0 << " Y: " << player[0]->getPosition()[0] << std::endl;
			Move();
		}
		//TODO: Game Over If > windowHeight
	}
	if (key == 'd' && player[0]->getDirection() != LEFT) {
		if (player[0]->getPosition()[1] < windowWidth) {
			player[0]->setDirection(RIGHT);
			player[0]->setLastP(player[0]->getPosition());
			pos[1]++;
			player[0]->setPosition(pos);
			std::cout << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position X = " << player[0]->getLastP()[1] << std::endl;
			std::cout << "PLAYER[" << 0 << "] last position Y = " << player[0]->getLastP()[0] << std::endl;
			std::cout << "Player segment " << 0 << " X: " << player[0]->getPosition()[1] << std::endl;
			std::cout << "Player segment " << 0 << " Y: " << player[0]->getPosition()[0] << std::endl;
			Move();
		}
		// TODO: Game Over If > windowWidth
	}
	tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);
}

void CoreGame::Move() {
	unsigned int 	i = 1;
	std::vector<int> pos;

	std::cout << std::endl;

	while (i < player.size()) {
		pos = player[i]->getPosition();

		switch (player[i]->getDirection()) {
			case UP: {
				std::cout << "UP\n";
				player[i]->setPosition(player[i - 1]->getLastP());
				player[i]->setLastP(pos);
				std::cout << "PLAYER[" << i << "] last position X = " << player[i]->getLastP()[1] << std::endl;
				std::cout << "PLAYER[" << i << "] last position Y = " << player[i]->getLastP()[0] << std::endl;
				pos[0]--;
				break;
			}
			case LEFT: {
				std::cout << "LEFT\n";
				player[i]->setPosition(player[i - 1]->getLastP());
				player[i]->setLastP(pos);
				std::cout << "PLAYER[" << i << "] last position X = " << player[i]->getLastP()[1] << std::endl;
				std::cout << "PLAYER[" << i << "] last position Y = " << player[i]->getLastP()[0] << std::endl;
				pos[1]--;
				break;
			}
			case DOWN: {
				std::cout << "DOWN\n";
				player[i]->setPosition(player[i - 1]->getLastP());
				player[i]->setLastP(pos);
				std::cout << "PLAYER[" << i << "] last position X = " << player[i]->getLastP()[1] << std::endl;
				std::cout << "PLAYER[" << i << "] last position Y = " << player[i]->getLastP()[0] << std::endl;
				pos[0]++;
				break;
			}
			case RIGHT: {
				std::cout << "RIGHT\n";
				player[i]->setPosition(player[i - 1]->getLastP());
				player[i]->setLastP(pos);
				std::cout << "PLAYER[" << i << "] last position X = " << player[i]->getLastP()[1] << std::endl;
				std::cout << "PLAYER[" << i << "] last position Y = " << player[i]->getLastP()[0] << std::endl;
				pos[1]++;
				break;
			}
			default: {
				player[i]->setDirection(UP);
				break;
			}
		}
		std::cout << "Player segment " << i << " X: " << player[i]->getPosition()[1] << std::endl;
		std::cout << "Player segment " << i << " Y: " << player[i]->getPosition()[0] << std::endl;
		i++;
	}
}
