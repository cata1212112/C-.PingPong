//
// Created by Cata on 5/24/2022.
//

#include "ball.h"
#include <math.h>
#include <iostream>
#include <vector>
#include <thread>

Ball& Ball::operator=(const Ball &other) {
    position = other.position;
    dir = other.dir;
    viteza = other.viteza;
    dim = other.dim;
    minge.setRadius(other.minge.getRadius());
    minge.setOrigin(other.minge.getOrigin());
    minge.setPosition(other.minge.getPosition());
    minge.setFillColor(other.minge.getFillColor());
    initial = other.initial;
    return *this;
}

void Ball::Initiliaze_Ball() {
    position = initial;
    float unghi = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX/RAND_MAX));
    std::cout << unghi << "\n";
    dir.x = sin(unghi);
    dir.y = cos(unghi);

    std::cout << position.x << " " << position.y << " " << dir.x << " " << dir.y << "\n";
}
