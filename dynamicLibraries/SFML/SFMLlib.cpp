//
// Created by Craig MAYO on 2017/06/16.
//

#include "SFMLlib.hpp"

gameControl::gameControl(int x) {
	std::cout<<"constuctor called"<<std::endl;
	sf::Window window(sf::VideoMode(x*25, x*25), "My window");

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

extern "C" gameControl* create(int x){
		return new gameControl(x);
}
extern "C" void destroy(gameControl* p) {
	delete p;
}


