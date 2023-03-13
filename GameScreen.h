//
// Created by Cata on 5/24/2022.
//

#ifndef PINGPONG_GAMESCREEN_H
#define PINGPONG_GAMESCREEN_H

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "ball.h"
#include <memory>


class GameScreen {
private:
    int screen_size_width;
    int screen_size_height;
    sf::RenderWindow *window;
    Ball minge;
    shared_ptr<Player> player1, player2;
public:
    GameScreen() : player1(nullptr), player2(nullptr) {}

    GameScreen(int x, int y, const Ball &_minge) : screen_size_width(x), screen_size_height(y) {
        minge = _minge;
        window = new sf::RenderWindow(sf::VideoMode(screen_size_width, screen_size_height), "Ping Pong");
        window->setActive(false);
        window->setFramerateLimit(60);
    }


    void set_pointers(shared_ptr<Player> &p1, shared_ptr<Player> &p2) {
        player1 = p1;
        player2 = p2;
    }

    void Randeaza();

    void MainLoop();

    void Citeste_Input();

    void Actualizeaza_Pozitii();

    void Check_Intersectie_Margini();

    int verifica_afara();
};


#endif //PINGPONG_GAMESCREEN_H
