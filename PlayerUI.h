//
// Created by Cata on 5/24/2022.
//

#ifndef PINGPONG_PLAYERUI_H
#define PINGPONG_PLAYERUI_H

#include <SFML/Graphics.hpp>
#include "pos.h"

class PlayerUI {
private:
    pos position;
    float width, height;
    float dir;
    sf::RectangleShape rectangle;
public:
    PlayerUI() {}

    PlayerUI(const pos &position, float width, float height, float dir) : position(position), width(width),
                                                                          height(height), dir(dir) {

        rectangle.setSize(sf::Vector2<float>(width, height));
        rectangle.setOrigin(width/2, height/2);
        rectangle.setPosition(sf::Vector2<float>(position.x, position.y));
        rectangle.setFillColor(sf::Color::White);
    }

    sf::Shape& get_shape() {
        return rectangle;
    }

    PlayerUI& operator=(const PlayerUI& other);

    PlayerUI& operator--(int);

    PlayerUI& operator++(int);

    void Afiseaza();

    const pos &getPosition() const {
        return position;
    }

};


#endif //PINGPONG_PLAYERUI_H
