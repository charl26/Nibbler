/*
    Created by Franco SCHEEPERS on 2017/06/19.
*/

#include "Food.hpp"

Food::Food() {}

Food::Food(const Food &food) {
    Food::operator=(food);
}

Food::Food(const std::vector<int> &position) : position(position) {
    std::cout << "Food Constructor Called" << std::endl;
}

Food Food::operator=(const Food &rhs) {
    Food::position = rhs.getPosition();

    return (*this);
}

const std::vector<int> &Food::getPosition() const {
    return position;
}

void Food::setPosition(const std::vector<int> &position) {
    Food::position = position;
}

Food::~Food() {
    std::cout << "Food Destructor Called" << std::endl;
}
