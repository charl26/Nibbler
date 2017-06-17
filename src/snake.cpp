//
// Created by Charl THERON on 2017/06/17.
//

#include "snake.hpp"

Snake::Snake(const std::vector<int> &position, bool isHead) : position(position), isHead(isHead) {
	std::cout << "Snake Constructor Called" << std::endl;
}

Snake::~Snake() {
	std::cout << "Snake Destructor Called" << std::endl;
}
