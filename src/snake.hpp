//
// Created by Charl THERON on 2017/06/17.
//

#ifndef NIBBLER_SNAKE_HPP
#define NIBBLER_SNAKE_HPP

#include <iostream>
#include <vector>

class Snake {
	std::vector<int> position;
	bool isHead;
public:
	Snake(const std::vector<int> &position, bool isHead);

	virtual ~Snake();
};

#endif //NIBBLER_SNAKE_HPP
