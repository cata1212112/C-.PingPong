//
// Created by Cata on 5/24/2022.
//

#include "Game.h"

using namespace std;

void Game::Start() {
    string nume_1, nume_2;
    cout << "Introduceti numele primului player: \n";
    getline(cin >> ws, nume_1);
    cout << "Introduceti numele celui de-al doilea player: \n";
    getline(cin >> ws, nume_2);

    player1 = shared_ptr<Player>(new Player(nume_1));
    player2 = shared_ptr<Player>(new Player(nume_2));

    ecran.set_pointers(player1, player2);
}

void Game::Ruleaza() {
    Start();
    ecran.MainLoop();
}