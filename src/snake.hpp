//
// Created by Charl THERON on 2017/06/17.
//

#ifndef NIBBLER_SNAKE_HPP
#define NIBBLER_SNAKE_HPP

#include <iostream>
#include <vector>

class Snake {
private:
	std::vector<int>    position;
	bool                head;

	Snake();
	Snake(const Snake &snake);

public:
	Snake(const std::vector<int> &position, bool isHead);
	Snake operator=(const Snake &rhs);
    const std::vector<int> &getPosition() const;
    void setPosition(const std::vector<int> &position);
    bool isHead() const;
    void setHead(bool Head);
	virtual ~Snake();
};

#endif
