//
// Created by Cata on 5/24/2022.
//

#ifndef PINGPONG_BALL_H
#define PINGPONG_BALL_H

#include "pos.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <random>
#include <vector>

using namespace std;

class Ball {
private:
    pos position;
    pos dir;
    float viteza;
    float dim;
    sf::CircleShape minge;
    pos initial;
public:
    Ball() : minge(sf::CircleShape(0)), initial({0, 0}) {}

    Ball(const pos &position, const pos &dir, float viteza, float dim) : position(position), dir(dir), viteza(viteza),
                                                                         dim(dim), initial(position) {
        minge.setRadius(dim);
        minge.setPosition(sf::Vector2<float>(position.x, position.y));
        minge.setOrigin(minge.getRadius(), minge.getRadius());
        minge.setFillColor(sf::Color::White);
    }

    Ball& operator=(const Ball &other);

    sf::Shape& to_draw() {
        return minge;
    }

    void set_dir(const pos &other) {
        dir = other;
    }

    void misca_minge() {
        position += (dir * viteza);
        minge.setPosition(sf::Vector2<float>(position.x, position.y));
    }

    pos get_pos() {
        return position;
    }

    pos get_dir() {
        return dir;
    }

    float getViteza() const {
        return viteza;
    }

    void Initiliaze_Ball();

    double get_raza() {
        return minge.getRadius();
    }
};


#endif //PINGPONG_BALL_H
