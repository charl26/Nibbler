//
// Created by Craig MAYO on 2017/06/16.
//

#ifndef NIBBLER_SFMLLIB_HPP
extern "C"
#define NIBBLER_SFMLLIB_HPP

#include <SFML/Window.hpp>
#include <iostream>

class gameControl {
public:
	gameControl(int x);
	~gameControl();
};

//gameControl* newlibinst();


// the types of the class factories
typedef gameControl* create_t(int x);
typedef void destroy_t(gameControl*);
#endif //NIBBLER_SFMLLIB_HPP
