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

const std::vector<Snake *> &CoreGame::getPlayer() const {
    return player;
}

void CoreGame::setPlayer(const std::vector<Snake *> &player) {
    CoreGame::player = player;
}

CoreGame::CoreGame() {
    CoreGame::setState(2);
    std::cout << "CoreGame Constructor Called" << std::endl;
    srand((unsigned) time(0));
}

void CoreGame::addSnakeSegment(const std::vector<int> &position, bool isHead) {
    Snake *snakeSegment = new Snake(position, isHead, UP);
    player.push_back(snakeSegment);
}

void CoreGame::SpawnFood() {
    if (CoreGame::food.size() < 5) {
        Food *food = new Food(CoreGame::RandomPosition());
        CoreGame::food.push_back(food);
    }
}

std::vector<int> CoreGame::RandomPosition() {
    int x = std::rand() % (CoreGame::getWindowWidth() * 20);
    int y = std::rand() % (CoreGame::getWindowHeight() * 20);
    std::vector<int> v = {x, y};

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

void CoreGame::MoveSegments(CoreGame *game) {
    unsigned int i = 1;
    std::vector<int> pos;

    while (i < player.size()) {
        pos = player[i]->getPosition();
        if (player[0]->getPosition()[0] == pos[0] && player[0]->getPosition()[1] == pos[1]) {
            game->setState(3);
        }
        player[i]->setPosition(player[i - 1]->getLastP());
        player[i]->setLastP(pos);
        i++;
    }
}

void CoreGame::MoveHead(CoreGame *game) {
    std::vector<int> pos;

    pos = player[0]->getPosition();
    switch (player[0]->getDirection()) {
        case UP: {
            if (player[0]->getPosition()[0] - 20 >= 0) {
                player[0]->setLastP(player[0]->getPosition());
                pos[0] -= 20;
                player[0]->setPosition(pos);
                MoveSegments(game);
            }
            break;
        }
        case LEFT: {
            if (player[0]->getPosition()[1] - 20 >= 0) {
                player[0]->setLastP(player[0]->getPosition());
                pos[1] -= 20;
                player[0]->setPosition(pos);
                MoveSegments(game);
            }
            break;
        }
        case DOWN: {
            if (player[0]->getPosition()[0] - (windowHeight * 20) - 70 <= windowHeight) {
                player[0]->setLastP(player[0]->getPosition());
                pos[0] += 20;
                player[0]->setPosition(pos);
                MoveSegments(game);
            }
            break;
        }
        case RIGHT: {
            if (player[0]->getPosition()[1] - (windowWidth * 20) - 70 <= windowWidth) {
                player[0]->setLastP(player[0]->getPosition());
                pos[1] += 20;
                player[0]->setPosition(pos);
                MoveSegments(game);
            }
            break;
        }
        default: {
            break;
        }
    }
}

const std::vector<Food *> &CoreGame::getFood() const {
    return food;
}

void CoreGame::setFood(const std::vector<Food *> &food) {
    CoreGame::food = food;
}
