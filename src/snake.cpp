//
// Created by Charl THERON on 2017/06/17.
//

#include "snake.hpp"

Snake::Snake(const std::vector<int> &position, bool head, int direction) : position(position), head(head), direction(direction) {
	std::cout << "Snake Constructor Called" << std::endl;
    Snake::lastP = position;
}

Snake::~Snake() {
	std::cout << "Snake Destructor Called" << std::endl;
}

const std::vector<int> &Snake::getPosition() const {
	return position;
}

void Snake::setPosition(const std::vector<int> &position) {
    Snake::lastP = Snake::position;
	Snake::position = position;
    //std::cout << "LAST POS Y: " << Snake::lastP[0] << "\nLAST POS X" << Snake::lastP[1] << std::endl;
    //std::cout << "CURRENT POS Y: " << Snake::position[0] << "\nCURRENT POS X" << Snake::position[1] << std::endl;
}

bool Snake::isHead() const {
	return head;
}

void Snake::setHead(bool Head) {
	Snake::head = Head;
}

Snake Snake::operator=(const Snake &rhs) {
	Snake::position = rhs.getPosition();
	Snake::head = rhs.isHead();

	return (*this);
}

Snake::Snake(const Snake &snake) {
	Snake::operator=(snake);
}

Snake::Snake() {}

int Snake::getDirection() const {
	return direction;
}

void Snake::setDirection(int direction) {
	Snake::direction = direction;
}

const std::vector<int> &Snake::getLastP() const {
	return lastP;
}

void Snake::setLastP(const std::vector<int> &lastP) {
	Snake::lastP = lastP;
}
