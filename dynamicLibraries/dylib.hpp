//
// Created by Charl THERON on 2017/06/14.
//

#ifndef DYLIB_HPP
#define DYLIB_HPP

#include "./../src/CoreGame.hpp"
#include <iostream>

class gameControl {
private:
	int ScreenW;
	int ScreenH;

public:
	gameControl(CoreGame *ref);
	void    draw();
	void    update();
	virtual ~gameControl();

	int getScreenW() const;
	void setScreenW(int ScreenW);
	int getScreenH() const;
	void setScreenH(int ScreenH);
};

typedef gameControl* create_t(CoreGame *ref);

#endif //DYLIB_HPP
