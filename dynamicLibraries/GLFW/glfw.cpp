//
// Created by Charl THERON on 2017/06/14.
//

#include "../dylib.hpp"
#include "glfw.hpp"

gameControl::gameControl() {
	GLFWwindow* window = glfwCreateWindow(640, 480, "My Title", NULL, NULL);
}


gameControl::~gameControl() {
	std::cout << "glfw Deconstructed" << std::endl;
	glfwTerminate();
}

extern "C" gameControl* create() {
	return new gameControl();
}