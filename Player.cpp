//
// Created by Cata on 5/24/2022.
//

#include "Player.h"


int Player::nextid = 0;

Player &Player::operator--(int) {
    paleta--;
    return *this;
}

Player &Player::operator++(int) {
    paleta++;
    return *this;
}

void Player::Afiseaza() {
    paleta.Afiseaza();
}