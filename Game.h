#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <unistd.h>
#include "Unit.h"
#include "UnitAI.h"

class Game
{
private:
    const int FIELD_SIZE_DEFAULT = 3;          
    int FIELD_SIZE; 

    Field *field;
    bool isGame;                         // флаг существования игры и останвки loopgame
    bool gameOver;                       // состяония ничьей

    int winner;         // 0-nobody, 1-X, 2-O

    Unit *human_one;
    Unit *human_two;

    UnitAI *comp_one; 
    UnitAI *comp_two; 

public:
    Game(){
       initGame();
    };
    ~Game() {
        std::cout << "End Game" << std::endl;
    }

    void initGame() {
        isGame = true; 
        gameOver = false;
        winner = 0;
        field = new Field(FIELD_SIZE_DEFAULT);  
        human_one = new Unit(X);    
        human_two = new Unit(O);

        comp_one = new UnitAI(X);    
        comp_two = new UnitAI(O);    
    }

    void drawField();
    void drawField(char figure);
   
    void gameLoopCompVsComp();
    void gameLoopPvP();
    void gameLoopPvE();

    void startGameMenu();
    void choiceFieldSize();
    void drawLogo();
    void drawMenu(); 

    void endGameMenu();

private:

};

#endif // !GAME_H
