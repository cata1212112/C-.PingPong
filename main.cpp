#include <iostream>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

#include "ball.h"
#include "PlayerUI.h"
#include "Player.h"
#include "Game.h"
#include "GameScreen.h"

using namespace std;

int main() {
    srand(time(NULL));
    Game joc;
    joc.Ruleaza();
    return 0;
}
