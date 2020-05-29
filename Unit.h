// у игрока могут быть несколько состояний

#ifndef UNUT_H
#define UNUT_H

#include <iostream>
#include "Field.h"

class Unit
{
protected:
    int figure;
    int winState = false;
public:
    Unit(Figure f);
    int makeMove(Field *field);
    int getFigure();
    ~Unit(){};

    bool checkWinState(Field *field);
    bool getState();
};

#endif // !UNIT_H