//
// Created by Craig MAYO on 2017/06/16.
//

#include "../dylib.hpp"
#include "SFMLlib.hpp"
#include "../../graphicsLibraries/SFML/include/SFML/Window/Keyboard.hpp"

sf::RenderWindow window;

gameControl::gameControl(CoreGame *ref) {
	ScreenH = ref->getWindowHeight();
	ScreenW = ref->getWindowWidth();
	coreGame = ref;
	window.create(sf::VideoMode(ScreenW, ScreenH), "My window");

	std::cout<<"constuctor called"<<std::endl;
}

gameControl::~gameControl() {
	std::cout<<"destuctor called"<<std::endl;
}

extern "C" {
	void gameControl::draw() {
		int snakelen = (int) coreGame->getPlayer().size();
		int snakeypos = coreGame->getPlayer()[0]->getPosition()[0];
		int snakexpos = coreGame->getPlayer()[0]->getPosition()[1];
        //std::vector<int>    tmp;

        //std::cout << "SNAKE LEN: " << snakelen << std::endl;

		//sf::Texture* node = new  sf::Texture[snakelen];
		//sf::Sprite* nodeimg = new sf::Sprite[snakelen];

		window.clear();
		// check all the window's events that were triggered since the last iteration of the loop

		sf::Event event;
		window.pollEvent(event);

		sf::Texture head;
		head.loadFromFile("Snake.png");
        //head.loadFromFile("ecogreen.png");

		sf::Sprite heading;
		heading.setTexture(head);
		//heading.setTextureRect({ -snakexpos, -snakeypos, ScreenW, ScreenH});

        heading.setPosition(sf::Vector2f(snakexpos, snakeypos));
        window.draw(heading);

        sf::Texture body;
        body.loadFromFile("Snake.png");
        //body.loadFromFile("ecogreen.png");
        sf::Sprite bodypart;
        bodypart.setTexture(body);

        sf::Texture food1;
        food1.loadFromFile("Snake.png");
        sf::Sprite food;
        food.setTexture(food1);
        int foodX, foodY;



        int bodyX, bodyY;
        for (int i = 1; i < snakelen; i++) {
            bodyY = coreGame->getPlayer()[i]->getPosition()[0];
            bodyX = coreGame->getPlayer()[i]->getPosition()[1];
            std::cout << "BODY Y: " << bodyY << "\nBODY X" << bodyX << std::endl;
            //bodypart.setTextureRect({ -bodyX, -bodyY, ScreenW, ScreenH});
            bodypart.setPosition(sf::Vector2f(bodyX, bodyY));
            window.draw(bodypart);
        }
		window.display();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            std::cout << "LINKS BLIKSEM" << std::endl;
            coreGame->MoveLeft();
            heading.setRotation(90);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            std::cout << "REGS BLIKSEM" << std::endl;
            coreGame->MoveRight();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            std::cout << "AF BLIKSEM" << std::endl;
            coreGame->MoveDown();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            std::cout << "OP BLIKSEM" << std::endl;
            coreGame->MoveUp();
        }
	}
}



void gameControl::update() {

}


int gameControl::getScreenW() {return ScreenW;}
void gameControl::setScreenW(int ScreenW) {gameControl::ScreenW = ScreenW;}
int gameControl::getScreenH() {return ScreenH;}
void gameControl::setScreenH(int ScreenH) {gameControl::ScreenH = ScreenH;}

extern "C" gameControl* create(CoreGame *ref){return new gameControl(ref);}
extern "C" void destroy(CoreGame* coreGame) { delete coreGame; }
extern "C" void *screen(gameControl *obj) {
	obj->draw();
	return (0);
};
