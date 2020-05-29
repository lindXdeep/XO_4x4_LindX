#ifndef UNITAI_H
#define UNITAI_H

#include "Unit.h"

class UnitAI : public Unit
{
protected:
    int FIELD_SIZE;
    int enemy;
public:
    UnitAI(Figure f) : Unit(f) {
        enemy = (f == X) ? O : X;
    };
    ~UnitAI(){};

    int makeMove(Field *field);

    bool checkPreWinningState(Field *field);
    bool checkOneEmptyCell(int arr[]);

private:
    void clearArray(int arr[]);
    int getEmptyIndex(int arr[]);
};
#endif // !UNITAI_H
