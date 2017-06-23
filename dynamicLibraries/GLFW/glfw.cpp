//
// Created by Charl THERON on 2017/06/14.
//

#include "../dylib.hpp"
#include "glfw.hpp"

struct snakeHead {

};

GLFWwindow *window;
gameControl::gameControl(CoreGame *ref) {
	ScreenH = ref->getWindowHeight();
	ScreenW = ref->getWindowWidth();
	coreGame = ref;
	if (glfwInit() == GLFW_FALSE) {
		std::cout << "glfw did not initialize!" << std::endl;
	}
	window = glfwCreateWindow(ScreenW, ScreenH, "Nibbler", NULL, NULL);
	if (!window) {
		glfwTerminate();
		std::cout << "glfw did not initialize window!" << std::endl;
	}
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	std::cout << "DYLIB GLFW Constructed" << std::endl;
}

gameControl::~gameControl() {
	std::cout << "glfw Deconstructed" << std::endl;
	glfwTerminate();
}

void processInput(GLFWwindow *window)
{
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void gameControl::draw() {
	if(!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		processInput(window);
		glfwGetFramebufferSize(window, &this->ScreenW, &this->ScreenH);
		glViewport(0, 0, this->ScreenW, this->ScreenH);
		glfwSwapBuffers(window);
		glfwSwapInterval(1);
		glfwPollEvents();
	}
}

void gameControl::update() {

}
int gameControl::getScreenW() { return ScreenW; }

void gameControl::setScreenW(int ScreenW) { gameControl::ScreenW = ScreenW; }

int gameControl::getScreenH() { return ScreenH; }

void gameControl::setScreenH(int ScreenH) { gameControl::ScreenH = ScreenH; }


extern "C" gameControl *create(CoreGame *ref) { return new gameControl(ref); }

extern "C" void destroy(CoreGame *coreGame) {
	glfwTerminate();
	delete coreGame;
}

extern "C" void *screen(gameControl *obj) {
	obj->draw();
	return (0);
};