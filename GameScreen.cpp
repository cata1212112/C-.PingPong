//
// Created by Cata on 5/24/2022.
//

#include "GameScreen.h"

void GameScreen::Actualizeaza_Pozitii() {
    window->draw(player1->to_draw());
    window->draw(player2->to_draw());
    window->draw(minge.to_draw());
}

void GameScreen::Randeaza() {

    window->display();
    minge.Initiliaze_Ball();
    while (window->isOpen()) {

        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            (*player1)++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            (*player1)--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            (*player2)++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            (*player2)--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            minge.Initiliaze_Ball();
        }

        int ok = verifica_afara();

        if (ok == -1) {
            minge.Initiliaze_Ball();
            player2->setScor(player2->getScor()+1);
        } else if (ok == 1) {
            minge.Initiliaze_Ball();
            player1->setScor(player1->getScor()+1);
        }
        sf::Font font;
        font.loadFromFile("arial.ttf");
        sf::Text scor_1;
        scor_1.setString(player1->getNume() + " " + to_string(player1->getScor()));
        scor_1.setFont(font);
        scor_1.setCharacterSize(24);
        scor_1.setPosition(sf::Vector2<float>(player1_score_x, player1_score_y));

        sf::Text scor_2;
        scor_2.setString(player2->getNume() + " " + to_string(player2->getScor()));
        scor_2.setFont(font);
        scor_2.setCharacterSize(24);
        scor_2.setPosition(sf::Vector2<float>(player2_score_x, player2_score_y));

        window->clear(sf::Color::Black);
        Check_Intersectie_Margini();
        minge.misca_minge();
        Actualizeaza_Pozitii();
        window->draw(scor_1);
        window->draw(scor_2);
        window->display();
    }
}

void GameScreen::MainLoop() {
    Randeaza();
}

void GameScreen::Check_Intersectie_Margini() {
    pos pos_minge = minge.get_pos();
    if (pos_minge.y - minge.get_raza() <= 0) {
        pos last_dir = minge.get_dir();
        last_dir.y *= -1;
        minge.set_dir(last_dir);
    }
    if (pos_minge.y + minge.get_raza() >= windo_heigth) {
        pos last_dir = minge.get_dir();
        last_dir.y *= -1;
        minge.set_dir(last_dir);
    }
//    vector<pair<double, double>> puncte;
//    puncte.clear();
    pos player_1 = player1->get_poz();
    pos player_2 = player2->get_poz();
    double rad = minge.get_raza();
    pos position = minge.get_pos();

    for (int i=0; i<16; i++) {
        double grade = (i * 45) * (M_PI / 180);
        pos pct;
        pct.x = rad * cos(position.x * grade) + position.x;
        pct.y = rad * sin(position.y * grade) + position.y;
        if (pct.x >= player_1.x - playerUI_width/2 && pct.x <= player_1.x + playerUI_width/2 && pct.y >= player_1.y - playerUI_height/2 && pct.y <= player_1.y + playerUI_height/2) {
            pos last_dir = minge.get_dir();
            last_dir.x *= -1;
            minge.set_dir(last_dir);
            break;
        }
        if (pct.x >= player_2.x - playerUI_width/2 && pct.x <= player_2.x + playerUI_width/2 && pct.y >= player_2.y - playerUI_height/2 && pct.y <= player_2.y + playerUI_height/2) {
            cout << "okkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk";
            pos last_dir = minge.get_dir();
            last_dir.x *= -1;
            minge.set_dir(last_dir);
            break;
        }
    }
}

int GameScreen::verifica_afara() {
    pos player_1 = player1->get_poz();
    pos player_2 = player2->get_poz();
    pos pos_minge = minge.get_pos();

    if (pos_minge.x - minge.get_raza() <= player_left_x - 30) {
        return -1;
    }
    if (pos_minge.x + minge.get_raza() >= player_right_x + playerUI_width + 30) {
        return 1;
    }
    return 0;
}