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

const std::list<Snake *, std::allocator<Snake *>> &CoreGame::getPlayer() const {
	return player;
}

void CoreGame::setPlayer(const std::list<Snake *, std::allocator<Snake *>> &player) {
	CoreGame::player = player;
}

const std::list<Food *, std::allocator<Food *>> &CoreGame::getFood() const {
	return food;
}

void CoreGame::setFood(const std::list<Food *, std::allocator<Food *>> &food) {
	CoreGame::food = food;
}

CoreGame::CoreGame() {
	std::cout << "CoreGame Constructor Called" << std::endl;
	srand((unsigned)time(0));
}

void CoreGame::addSnakeSegment(const std::vector<int> &position, bool isHead) {
	Snake *snakeSegment = new Snake(position, isHead);
	player.push_back(snakeSegment);
}

void CoreGame::SpawnFood() {
	if (CoreGame::food.size() < 5) {
		Food *food = new Food(CoreGame::RandomPosition());
		CoreGame::food.push_back(food);
	}
}

std::vector<int> CoreGame::RandomPosition() {
	int x = std::rand() / CoreGame::windowWidth;
	int y = std::rand() / CoreGame::windowHeight;
	std::vector<int> v = {x , y};
	return (v);
}
