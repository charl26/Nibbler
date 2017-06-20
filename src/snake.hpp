//
// Created by Charl THERON on 2017/06/17.
//

#ifndef NIBBLER_SNAKE_HPP
# define NIBBLER_SNAKE_HPP
# define UP 1
# define LEFT 2
# define DOWN 3
# define RIGHT 4

#include <iostream>
#include <vector>

class Snake {
private:
	std::vector<int>    position;
	bool                head;
	int					direction;
	std::vector<int>	lastP;

	Snake();
	Snake(const Snake &snake);

public:
	Snake(const std::vector<int> &position, bool isHead, int direction);
	Snake operator=(const Snake &rhs);
    const std::vector<int> &getPosition() const;
    void setPosition(const std::vector<int> &position);
    bool isHead() const;
    void setHead(bool Head);
	int getDirection() const;
	const std::vector<int> &getLastP() const;
	void setLastP(const std::vector<int> &lastP);
	void setDirection(int direction);
	virtual ~Snake();
};

#endif
