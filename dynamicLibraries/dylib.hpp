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
	CoreGame *coreGame;
public:
	gameControl(CoreGame *ref);
	void    draw();
	void    update();
	virtual ~gameControl();

	int getScreenW();
	void setScreenW(int ScreenW);
	int getScreenH();
	void setScreenH(int ScreenH);
};

typedef gameControl* create_t(CoreGame *ref);
typedef void destroy_t(gameControl*);
typedef void* screen_t(gameControl *obj);

#endif
