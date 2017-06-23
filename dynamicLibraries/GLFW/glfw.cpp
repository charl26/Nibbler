//
// Created by Charl THERON on 2017/06/14.
//

#include "../dylib.hpp"
#include "glfw.hpp"

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

void gameControl::processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
		switch (coreGame->getPlayer()[0]->getDirection()) {
			case LEFT: {
				coreGame->getPlayer()[0]->setDirection(DOWN);
				break;
			}
			case RIGHT: {
				coreGame->getPlayer()[0]->setDirection(UP);
				break;
			}
			case UP: {
				coreGame->getPlayer()[0]->setDirection(LEFT);
				break;
			}
			case DOWN: {
				coreGame->getPlayer()[0]->setDirection(RIGHT);
				break;
			}
			default: {
				break;
			}
		}
	}
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
		switch (coreGame->getPlayer()[0]->getDirection()) {
			case LEFT: {
				coreGame->getPlayer()[0]->setDirection(UP);
				break;
			}
			case RIGHT: {
				coreGame->getPlayer()[0]->setDirection(DOWN);
				break;
			}
			case UP: {
				coreGame->getPlayer()[0]->setDirection(RIGHT);
				break;
			}
			case DOWN: {
				coreGame->getPlayer()[0]->setDirection(LEFT);
				break;
			}
			default: {
				break;
			}
		}
	}
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

void gameControl::draw() {
	if (!glfwWindowShouldClose(window)) {
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glfwGetFramebufferSize(window, &this->ScreenW, &this->ScreenH);
		glViewport(0, 0, this->ScreenW, this->ScreenH);
		glfwSwapBuffers(window);
		glfwSwapInterval(1);
		processInput(window);
		glfwPollEvents();
	} else {
		glfwTerminate();
		exit(0);
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