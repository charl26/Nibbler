//
// Created by Charl THERON on 2017/06/17.
//

#include "snake.hpp"

Snake::Snake(const std::vector<int> &position, bool isHead) : position(position), isHead(isHead) {
	std::cout << "Constructor Called" << std::endl;
}

Snake::~Snake() {
	std::cout << "Destructor Called" << std::endl;
}
