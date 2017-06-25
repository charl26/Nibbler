//
// Created by Craig MAYO on 2017/06/16.
//

#include "../dylib.hpp"
#include "SFMLlib.hpp"

gameControl::gameControl(CoreGame *ref) {
	ScreenH = ref->getWindowHeight();
	std::cout<<ScreenH<<std::endl;
	ScreenW = ref->getWindowWidth();

	std::cout<<"constuctor called"<<std::endl;
	sf::Window window(sf::VideoMode(ScreenW, ScreenH), "My window");

	// run the program as long as the window is open
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}

gameControl::~gameControl() {
	std::cout<<"destuctor called"<<std::endl;
}

void gameControl::draw() {

}

void gameControl::update() {

}


int gameControl::getScreenW() {return ScreenW;}
void gameControl::setScreenW(int ScreenW) {gameControl::ScreenW = ScreenW;}
int gameControl::getScreenH() {return ScreenH;}
void gameControl::setScreenH(int ScreenH) {gameControl::ScreenH = ScreenH;}

extern "C" gameControl* create(CoreGame *ref){return new gameControl(ref);}
extern "C" void destroy(CoreGame* coreGame) {delete coreGame;}
