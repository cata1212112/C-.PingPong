//
// Created by Cata on 5/24/2022.
//

#ifndef PINGPONG_GAME_H
#define PINGPONG_GAME_H

#include "GameScreen.h"
#include "pos.h"
#include "Player.h"

class Game {
private:
    GameScreen ecran;
    shared_ptr<Player> player1, player2;
public:
    Game() : ecran(window_width, windo_heigth,Ball(pos({ball_start_x, ball_start_y}), pos({0, 0}), ball_speed, ball_dim)) {}

    void Start();

    void Ruleaza();
};



#endif //PINGPONG_GAME_H
