//
// Created by Charl THERON on 2017/06/14.
//

#include "../dylib.hpp"
#include "glfw.hpp"


gameControl::gameControl(CoreGame *ref) {
	ScreenH = ref->getWindowHeight();
	ScreenW = ref->getWindowWidth();

	GLFWwindow* window;
	/* Initialize the library */
	if (!glfwInit())
		std::cout << "glfw did not initialize!" << std::endl;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(ScreenW, ScreenH, "Nibbler", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		std::cout << "glfw did not initialize window!" << std::endl;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);
		int width, height;
		glfwGetFramebufferSize(window, &width, &height);
		glViewport(0, 0, width, height);


		/* Swap front and back buffers */
		glfwSwapBuffers(window);
		glfwSwapInterval(1);

		/* Poll for and process events */
		glfwPollEvents();

	}

	glfwTerminate();
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

extern "C" gameControl* create(CoreGame *ref){return new gameControl(ref);}

extern "C" void destroy(CoreGame* coreGame) { delete coreGame; }