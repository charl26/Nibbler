//
// Created by Charl THERON on 2017/06/14.
//

#ifndef DYLIB_HPP
#define DYLIB_HPP

#include <iostream>

class gameControl {

public:
	gameControl();
	virtual ~gameControl();
};

typedef gameControl* create_t();

#endif //DYLIB_HPP
