//
// Created by Charl THERON on 2017/06/14.
//


#include "glfw.hpp"

gameControl::gameControl(int windowWidth ,int windowHeight) {
	this->widowHeight = windowHeight;
	this->widowWidth = windowWidth;
	glfwInit();
	std::cout << "glfw Constructed" << std::endl;
	createWindow();
	glfwSetKeyCallback(window, keyHooks);
	updateWindow();
}

void gameControl::createWindow() {
	this->window = glfwCreateWindow(this->widowWidth, this->widowHeight, "GLFW WINDOW", NULL, NULL);
	if(!window) {
		std::cout << "ERROR : Window Failed" << std::endl;
		delete(this);
	}
	glfwMakeContextCurrent(window);
}

gameControl::~gameControl() {
	std::cout << "glfw Deconstructed" << std::endl;
	glfwTerminate();
}

void gameControl::updateWindow() {

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}
	glfwDestroyWindow(window);
}

void gameControl::keyHooks(GLFWwindow *window, int key, int action) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GLFW_TRUE);
}
