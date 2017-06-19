//
// Created by Franco SCHEEPERS on 2017/06/19.
//

#ifndef NIBBLER_FOOD_H
#define NIBBLER_FOOD_H

#include <vector>
#include <iostream>

class Food {
private:
    std::vector<int> position;

public:
    Food(const std::vector<int> &position);
    virtual ~Food();
    const std::vector<int> &getPosition() const;
    void setPosition(const std::vector<int> &position);
};

#endif //NIBBLER_FOOD_H
