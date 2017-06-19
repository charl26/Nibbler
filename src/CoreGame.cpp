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

CoreGame::CoreGame() {
	std::cout << "CoreGame Constructor Called" << std::endl;
}

void CoreGame::addSnakeSegment(const std::vector<int> &position, bool isHead) {
	Snake *snakeSegment = new Snake(position, isHead);
	player.push_back(snakeSegment);
}
