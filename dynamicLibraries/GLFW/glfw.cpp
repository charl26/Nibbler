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

void gameControl::controls(){
	int esc = glfwGetKey(window, GLFW_KEY_ESCAPE);
	int left = glfwGetKey(window, GLFW_KEY_LEFT);
	int right = glfwGetKey(window, GLFW_KEY_RIGHT);
	int one = glfwGetKey(window, GLFW_KEY_1);
	int two = glfwGetKey(window, GLFW_KEY_2);
	int three = glfwGetKey(window, GLFW_KEY_3);

	if (left == GLFW_PRESS){
		switch (coreGame->getPlayer()[0]->getDirection()) {
			case LEFT:
			{
				coreGame->getPlayer()[0]->setDirection(DOWN);
				break;
			}
			case RIGHT:
			{
				coreGame->getPlayer()[0]->setDirection(UP);
				break;
			}
			case UP:
			{
				coreGame->getPlayer()[0]->setDirection(LEFT);
				break;
			}
			case DOWN:
			{
				coreGame->getPlayer()[0]->setDirection(RIGHT);
				break;
			}
			default:
			{
				break;
			}
		}
	}
	if (right == GLFW_PRESS){
		switch (coreGame->getPlayer()[0]->getDirection()) {
			case LEFT:
			{
				coreGame->getPlayer()[0]->setDirection(UP);
				break;
			}
			case RIGHT:
			{
				coreGame->getPlayer()[0]->setDirection(DOWN);
				break;
			}
			case UP:
			{
				coreGame->getPlayer()[0]->setDirection(RIGHT);
				break;
			}
			case DOWN:
			{
				coreGame->getPlayer()[0]->setDirection(LEFT);
				break;
			}
			default:
			{
				break;
			}
		}
	}
	if (esc == GLFW_PRESS){
		exit (1);
	}
	if (one == GLFW_PRESS){
		exit (1);
	}
	if (two == GLFW_PRESS){
		exit (1);
	}
	if (three == GLFW_PRESS){
		exit (1);
	}
}

void gameControl::draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glfwGetFramebufferSize(window, &this->ScreenW, &this->ScreenH);
	glViewport(0, 0, this->ScreenW, this->ScreenH);
	glfwSwapBuffers(window);
	glfwSwapInterval(1);
	controls();
	glfwPollEvents();
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