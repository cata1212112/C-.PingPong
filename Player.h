//
// Created by Cata on 5/24/2022.
//

#ifndef PINGPONG_PLAYER_H
#define PINGPONG_PLAYER_H

#include "PlayerUI.h"
#include "pos.h"
#include "constante.h"

using namespace std;

class Player {
private:
    static int nextid;
    int id;
    string nume;
    PlayerUI paleta;
    int scor;
public:
    Player() {

    }

    Player(const string &_nume) : id(nextid++), nume(_nume) {
        scor = 0;
        if (id == 0) {
            paleta = PlayerUI(pos({player_left_x, player_left_y}), playerUI_width, playerUI_height, playerUI_speed);
        } else {
            paleta = PlayerUI(pos({player_right_x, player_right_y}), playerUI_width, playerUI_height, playerUI_speed);
        }
    }

    sf::Shape& to_draw() {
        return paleta.get_shape();
    }

    Player& operator--(int);

    Player& operator++(int);

    void Afiseaza();

    pos get_poz() {
        return paleta.getPosition();
    }

    int getScor() const {
        return scor;
    }

    void setScor(int scor) {
        Player::scor = scor;
    }

    const string &getNume() const {
        return nume;
    }
};


#endif //PINGPONG_PLAYER_H
