//
// Created by Charl THERON on 2017/06/14.
//

#ifndef NIBBLER_GLFW_HPP
#define NIBBLER_GLFW_HPP

#include "../../graphicsLibraries/glfw/include/GLFW/glfw3.h"
#include <iostream>

class gameControl {
	int widowWidth;
	int widowHeight;
	GLFWwindow* window;

public:
	gameControl(int ,int);
	void createWindow();
	void updateWindow();
	static void keyHooks(GLFWwindow* window, int key, int action);
	virtual ~gameControl();
};

#endif //NIBBLER_GLFW_HPP
