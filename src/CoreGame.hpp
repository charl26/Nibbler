//
// Created by Charl THERON on 2017/06/09.
//

#ifndef NIBBLER_COREGAME_HPP
#define NIBBLER_COREGAME_HPP

#include <iostream>
#include <list>
#include "snake.hpp"

#define MaxWindow 700
#define MinWindow 50

class CoreGame {
	int windowWidth;
	int windowHeight;
	std::list<Snake*> player;
public:
	CoreGame();

	int getWindowWidth() const;

	void setWindowWidth(int windowWidth);

	int getWindowHeight() const;

	void setWindowHeight(int windowHeight);

	const std::list<Snake *, std::allocator<Snake *>> &getPlayer() const;

	void setPlayer(const std::list<Snake *, std::allocator<Snake *>> &player);

	void addSnakeSegment(const std::vector<int> &position, bool isHead);
};

#endif //NIBBLER_COREGAME_HPP
