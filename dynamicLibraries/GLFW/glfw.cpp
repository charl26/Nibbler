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
	glMatrixMode(GL_PROJECTION);

	std::cout << "DYLIB GLFW Constructed" << std::endl;
}

gameControl::~gameControl() {
	std::cout << "glfw Deconstructed" << std::endl;
	glfwTerminate();
}

void gameControl::processInput(GLFWwindow *window) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
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
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

void display(CoreGame *coreGame) {
	static int boxleft = 100,
			boxbottom = 100;
	int boxwidth = 50,
			boxheight = 50;

	int screenwidth = 1200, screenheight = 1200;
	// clear last frame
	glClear(GL_COLOR_BUFFER_BIT);

	// calculate screen space coordinates
	float left = (float) boxleft / screenwidth,
			right = left + (float) boxwidth / screenwidth,
			bottom = (float) boxbottom / screenheight,
			top = bottom + (float) boxheight / screenheight;

	if (coreGame->getPlayer()[0]->getDirection() == RIGHT) {
		boxleft--;
	}
	else if (coreGame->getPlayer()[0]->getDirection() == LEFT) {
		boxleft++;
	}
	else if (coreGame->getPlayer()[0]->getDirection() == DOWN) {
		boxbottom--;
	}
	else {
		boxbottom++;
	}
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(left, top);
	glVertex2f(right, top);
	glVertex2f(right, bottom);
	glVertex2f(left, bottom);
	glEnd();
	glFlush();

}

void gameControl::draw() {
	if (glfwWindowShouldClose(window) == GLFW_FALSE) {
		window = glfwGetCurrentContext();
		processInput(window);
		display(coreGame);
		glfwGetFramebufferSize(window, &this->ScreenW, &this->ScreenH);
		glfwSwapBuffers(window);
		glfwSwapInterval(1);
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