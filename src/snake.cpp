//
// Created by Charl THERON on 2017/06/17.
//

#include "snake.hpp"

Snake::Snake(const std::vector<int> &position, bool head) : position(position), head(head) {
	std::cout << "Snake Constructor Called" << std::endl;
}

Snake::~Snake() {
	std::cout << "Snake Destructor Called" << std::endl;
}

const std::vector<int> &Snake::getPosition() const {
	return position;
}

void Snake::setPosition(const std::vector<int> &position) {
	Snake::position = position;
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