//
// Created by Craig MAYO on 2017/06/19.
//

#include "../dylib.hpp"
#include "SDL2lib.hpp"

gameControl::gameControl(CoreGame *ref) {
	ScreenH = ref->getWindowHeight();
	ScreenW = ref->getWindowWidth();

	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window *window = SDL_CreateWindow(
			"Nibbler",
			100,
			100,
			ScreenW,
			ScreenH,
			0
	);

	if (window == NULL) {
		printf("Could not create window: %s\n", SDL_GetError());
	}

	SDL_Event event;
	while (SDL_PollEvent(&event)) {
			/* handle your event here */
	}

	SDL_Delay(3000);

	SDL_DestroyWindow(window);

	SDL_Quit();
}

gameControl::~gameControl() {

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