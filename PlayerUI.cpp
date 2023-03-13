//
// Created by Cata on 5/24/2022.
//

#include <iostream>
#include "PlayerUI.h"
#include "constante.h"

PlayerUI &PlayerUI::operator=(const PlayerUI &other) {
    position = other.position;
    width = other.width;
    height = other.height;
    dir = other.dir;
    rectangle.setOrigin(other.rectangle.getOrigin());
    rectangle.setSize(other.rectangle.getSize());
    rectangle.setFillColor(other.rectangle.getFillColor());
    rectangle.setPosition(other.rectangle.getPosition());
    return *this;
}

PlayerUI &PlayerUI::operator--(int) {
    if (position.y + dir + playerUI_height/2 <= windo_heigth) {
        position.y += dir;
        rectangle.setPosition(sf::Vector2<float>(position.x, position.y));
    }
    return *this;
}

PlayerUI &PlayerUI::operator++(int) {
    if (position.y - dir - playerUI_height/2 >= 0) {
        position.y -= dir;
        rectangle.setPosition(sf::Vector2<float>(position.x, position.y));
    }
    return *this;
}

void PlayerUI::Afiseaza() {
    std::cout << position.y << "\n";
}