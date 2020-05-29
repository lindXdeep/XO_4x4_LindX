#include <iostream>

#ifndef FIELD_H
#define FIELD_H

enum Figure {
    X = 1,
    O = 2,
};

class Field
{
private:
    const int FIELD_SIZE_DEFAULT = 3;          
    int FIELD_SIZE;                             
    int **gameField;
    char symbol[3] = {' ','X','O'};             // Символы для рисования.
public:
    Field(int sizeField){
        FIELD_SIZE = sizeField;
        initField();
    };
    Field(){
        FIELD_SIZE = FIELD_SIZE_DEFAULT; 
        initField();    
    };

    ~Field(){
        //TODO: уничтожить массив game Field
    };

    void setFieldSize(const int fieldSize);
    int getFieldSize();

    int &setFigure(int x, int y);
    char getFigure(int x, int y);

    int getSymbol(int x, int y);

    void initField();
};

#endif // !FIELD_H