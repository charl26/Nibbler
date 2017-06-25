//
// Created by Charl THERON on 2017/06/09.
//

#include "CoreGame.hpp"

int CoreGame::getWindowWidth() const {
    return windowWidth;
}

void CoreGame::setWindowWidth(int windowWidth) {
    CoreGame::windowWidth = windowWidth;
}

int CoreGame::getWindowHeight() const {
    return windowHeight;
}

void CoreGame::setWindowHeight(int windowHeight) {
    CoreGame::windowHeight = windowHeight;
}

const std::list<Food *, std::allocator<Food *>> &CoreGame::getFood() const {
    return food;
}

const std::vector<Snake *> &CoreGame::getPlayer() const {
    return player;
}

void CoreGame::setPlayer(const std::vector<Snake *> &player) {
    CoreGame::player = player;
}

void CoreGame::setFood(const std::list<Food *, std::allocator<Food *>> &food) {
    CoreGame::food = food;
}

CoreGame::CoreGame() {
    CoreGame::setState(2);
    std::cout << "CoreGame Constructor Called" << std::endl;
    srand((unsigned) time(0));
}

void CoreGame::addSnakeSegment(const std::vector<int> &position, bool isHead) {
    Snake *snakeSegment = new Snake(position, isHead, UP);
    if (snakeSegment->isHead()) {
        snakeSegment->setLastP(position);
        //std::cout << "LAST POS Y: " << snakeSegment->getLastP()[0] << "\nLAST POS X" << snakeSegment->getLastP()[1] << std::endl;
    }
    player.push_back(snakeSegment);
}

void CoreGame::SpawnFood() {
    if (CoreGame::food.size() < 5) {
        Food *food = new Food(CoreGame::RandomPosition());
        CoreGame::food.push_back(food);
    }
}

std::vector<int> CoreGame::RandomPosition() {
    int x = std::rand() % CoreGame::getWindowWidth();
    int y = std::rand() % CoreGame::getWindowHeight();
    std::vector<int> v = {x, y};

    std::cout << "Food Random X: " << x << std::endl;
    std::cout << "Food Random Y: " << y << std::endl;
    return (v);
}

CoreGame CoreGame::operator=(const CoreGame &rhs) {
    CoreGame::food = rhs.getFood();
    CoreGame::player = rhs.getPlayer();
    CoreGame::windowWidth = rhs.getWindowWidth();
    CoreGame::windowHeight = rhs.getWindowHeight();

    return (*this);
}

CoreGame::CoreGame(const CoreGame &coreGame) {
    CoreGame::operator=(coreGame);
}

int CoreGame::getState() const {
    return state;
}

void CoreGame::setState(int state) {
    CoreGame::state = state;
}

CoreGame::~CoreGame() {}

void CoreGame::CheckInput() {

}

void CoreGame::MoveLeft() {
    std::vector<int>    pos;

    pos = player[0]->getPosition();
    if (player[0]->getDirection() != RIGHT) {
        player[0]->setDirection(LEFT);
        pos[1]-= 25;
        player[0]->setPosition(pos);
        MoveSegments();
        //std::cout << "LAST POS Y: " << player[0]->getLastP()[0] << "\nLAST POS X" << player[0]->getLastP()[1] << std::endl;
    }
}

void CoreGame::MoveRight() {
    std::vector<int>    pos;

    pos = player[0]->getPosition();
    if (player[0]->getDirection() != LEFT) {
        player[0]->setDirection(RIGHT);
        pos[1]+= 25;
        player[0]->setPosition(pos);
        MoveSegments();
        //std::cout << "LAST POS Y: " << player[0]->getLastP()[0] << "\nLAST POS X" << player[0]->getLastP()[1] << std::endl;
    }
}

void CoreGame::MoveUp() {
    std::vector<int>    pos;

    pos = player[0]->getPosition();
    if (player[0]->getDirection() != DOWN) {
        player[0]->setDirection(UP);
        pos[0]-= 25;
        player[0]->setPosition(pos);
        MoveSegments();
        //std::cout << "LAST POS Y: " << player[0]->getLastP()[0] << "\nLAST POS X" << player[0]->getLastP()[1] << std::endl;
    }
}

void CoreGame::MoveDown(){
    std::vector<int>    pos;

    pos = player[0]->getPosition();
    if (player[0]->getDirection() != UP) {
        player[0]->setDirection(DOWN);
        pos[0]+= 25;
        player[0]->setPosition(pos);
        MoveSegments();
        //int i = 1;
        /*while (i < player.size()) {
            pos = player[i - 1]->getLastP();
            player[i]->setPosition(pos);


            std::cout << "Player segment " << i << " X: " << player[i]->getPosition()[1] << std::endl;
            std::cout << "Player segment " << i << " Y: " << player[i]->getPosition()[0] << std::endl;
            i++;
        }*/
        //std::cout << "LAST POS Y: " << player[0]->getLastP()[0] << "\nLAST POS X" << player[0]->getLastP()[1] << std::endl;
    }
}



void CoreGame::MoveSegments() {
    unsigned int i = 1;
    std::vector<int> pos;
    //std::vector<int> defPos;

   // defPos = player[0]->getLastP();

    while (i < player.size()) {
        pos = player[i - 1]->getLastP();
        player[i]->setPosition(pos);


        //std::cout << "Player segment " << i << " X: " << player[i]->getPosition()[1] << std::endl;
        //std::cout << "Player segment " << i << " Y: " << player[i]->getPosition()[0] << std::endl;
        i++;
    }
}

void CoreGame::MoveHead() {
//    unsigned int 	i = 1;
    std::vector<int> pos;
    std::vector<int> foodPos;

    //player[0]->setLastP(player[0]->getPosition());
    SpawnFood();

    std::list<Food *, std::allocator<Food *>> food = CoreGame::getFood();

    //pos = {player[0]->getPosition()[0], player[0]->getPosition()[1]};

    //addSnakeSegment(pos, false);
    //pos = player[0]->getPosition();
    switch (player[0]->getDirection()) {
        case UP: {
            MoveUp();
            MoveSegments();
            break;
        }

        case LEFT: {
            MoveLeft();
            MoveSegments();
            break;
        }
        case DOWN: {
            MoveDown();
            MoveSegments();
            break;
        }
        case RIGHT: {
            MoveRight();
            MoveSegments();
            break;
        }
        default : {
            MoveUp();
            MoveSegments();
        }
    }
}

