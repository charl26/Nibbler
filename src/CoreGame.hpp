//
// Created by Charl THERON on 2017/06/09.
//

#ifndef NIBBLER_COREGAME_HPP

# define NIBBLER_COREGAME_HPP
# define MaxWindow 700
# define MinWindow 50

#include <iostream>
#include <list>
#include "snake.hpp"
#include "Food.hpp"

class CoreGame {
private:
	int windowWidth;
	int windowHeight;
	std::list<Snake *> player;
	std::list<Food *> food;

    CoreGame(const CoreGame &coreGame);
    std::vector<int> RandomPosition();

public:
	CoreGame();
    CoreGame operator=(const CoreGame &rhs);
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
    virtual ~CoreGame();
};

#endif //NIBBLER_COREGAME_HPP
