//
// Created by Charl THERON on 2017/06/09.
//

#ifndef NIBBLER_COREGAME_HPP
#define NIBBLER_COREGAME_HPP

#include <iostream>
#include <list>
#include "snake.hpp"
#include "Food.hpp"

#define MaxWindow 700
#define MinWindow 50

#define GLFWLIB "../dynamicLibraries/GLFW/GLFWlib.so"
#define SDL2LIB "../dynamicLibraries/SDL2/SDL2lib.so"
#define SMFLLIB "../dynamicLibraries/SMFL/SFMLlib.so"

class CoreGame {
private:
	int windowWidth;
	int windowHeight;
	std::list<Snake *> player;
	std::list<Food *> food;

	std::vector<int> RandomPosition();

public:
	CoreGame();
	int getWindowWidth() const;
	void setWindowWidth(int windowWidth);
	int getWindowHeight() const;
	void setWindowHeight(int windowHeight);
	const std::list<Snake *, std::allocator<Snake *>> &getPlayer() const;
	void setPlayer(const std::list<Snake *, std::allocator<Snake *>> &player);
	void addSnakeSegment(const std::vector<int> &position, bool isHead);
	const std::list<Food *, std::allocator<Food *>> &getFood() const;
	void setFood(const std::list<Food *, std::allocator<Food *>> &food);
	void SpawnFood();
};

#endif //NIBBLER_COREGAME_HPP
