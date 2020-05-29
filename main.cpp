#include <iostream>
using namespace std;

#include "Game.h"

int main() {

    Game *game = new Game();
        
    game -> startGameMenu();   

    delete game;         
       
    return 0;
}