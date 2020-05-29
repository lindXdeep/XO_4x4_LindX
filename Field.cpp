#include "Field.h"
#include <unistd.h>
// Установить фигурку на поле по координате
// (x,y) = X    or   (x,y) = O
int &Field::setFigure(int x, int y){

    x = (x < 0) ? 0 : (x > FIELD_SIZE -1) ? FIELD_SIZE -1 : x;
    y = (y < 0) ? 0 : (y > FIELD_SIZE -1) ? FIELD_SIZE -1 : y;

    if (gameField[x][y] == X || gameField[x][y] == O)
    {
        std::cout << "this cell is occupied!!! " << std::endl;
        sleep(1);
    }
    return gameField[x][y];
}

// Возвращает фигурку по кооординате. фигурку на поле
char Field::getFigure(int x, int y){
    
    x = (x < 0) ? 0 : (x > FIELD_SIZE -1) ? FIELD_SIZE -1 : x;
    y = (y < 0) ? 0 : (y > FIELD_SIZE -1) ? FIELD_SIZE -1 : y;
    
    return symbol[gameField[x][y]];
}

int Field::getSymbol(int x, int y) {
    return gameField[x][y];
}

void Field::setFieldSize(const int fieldSize){
    FIELD_SIZE = fieldSize;
}

int Field::getFieldSize() {
    return FIELD_SIZE;
}

void Field::initField(){

    std::cout << "Set field size: " << FIELD_SIZE << std::endl;

    gameField = new int*[FIELD_SIZE];

    for (int i = 0; i < FIELD_SIZE; i++)
        gameField[i] = new int[FIELD_SIZE];

    for (int i = 0; i < FIELD_SIZE; i++)
        for (int j = 0; j < FIELD_SIZE; j++)
            gameField[i][j] = 0;      
}