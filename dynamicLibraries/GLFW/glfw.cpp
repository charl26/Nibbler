//
// Created by Charl THERON on 2017/06/14.
//

#include "../dylib.hpp"
#include "glfw.hpp"

gameControl::gameControl(CoreGame &ref) {
	ScreenH = ref.getWindowHeight();
	ScreenW = ref.getWindowWidth();
	GLFWwindow* window = glfwCreateWindow(ScreenH, ScreenW, "Nibbler", NULL, NULL);
}


gameControl::~gameControl() {
	std::cout << "glfw Deconstructed" << std::endl;
	glfwTerminate();
}

void gameControl::draw() {

}

void gameControl::update() {

}

int gameControl::getScreenW() const {return ScreenW;}
void gameControl::setScreenW(int ScreenW) {gameControl::ScreenW = ScreenW;}
int gameControl::getScreenH() const {return ScreenH;}
void gameControl::setScreenH(int ScreenH) {gameControl::ScreenH = ScreenH;}

extern "C" gameControl* create() {return new gameControl();}