#include "UnitAI.h"
#include<unistd.h>

// Заполнение массива состяоний нулями
void UnitAI::clearArray(int arr[]) {
    int i = 0;      
    do{
        arr[i] = 0;
    } while (++i < FIELD_SIZE);
}

// Возвращает индекс нулевого элемента массива
int UnitAI::getEmptyIndex(int arr[]) {
    int i = 0;
    do {
        if(arr[i] == 0)
            return i;
    } while (++i < FIELD_SIZE); 
    return -1;   
}   

// Естли в массиве всего 1 пустая ячейка?
bool UnitAI::checkOneEmptyCell(int arr[]) {
    int count = 0;
    for (int i = 0; i < FIELD_SIZE; ++i)
    	if(arr[i] == 0) count++;

    return (count == 0 || count > 1) ? false : true;
}

bool UnitAI::checkPreWinningState(Field *field) {

    //Создадим два массива для проверки сотояний
    int index = 0;                          // индекс для массивов состояний
    int statePlayer01[FIELD_SIZE];          // Me
            clearArray(statePlayer01);

    int statePlayer02[FIELD_SIZE];          // Enemy
            clearArray(statePlayer02);    

    int i = 0;
    do {  // Проходимся по горизантальным линиям  
        int j = 0;
        do {
            if(field -> getSymbol(i,j) == figure ) statePlayer01[index] = 1; // Еденица так как нам не важна фигурка
            if(field -> getSymbol(i,j) == enemy  ) statePlayer02[index] = 1; 
            index++;
        } while (++j < FIELD_SIZE);

        // теперь надо проверить состояния предпобеды путем поиска наличия пустой одной клетки 
        // Если у нас выигрышная ситуация а у врага нет тогда делаем ход на свою ячейку
        if(checkOneEmptyCell(statePlayer01) && !checkOneEmptyCell(statePlayer02))
        {
            int jdx = getEmptyIndex(statePlayer01); 
            field -> setFigure(i, jdx) = figure;
            return 0;
        }

        // Если враг в состоянии предпобеды тогда то действуем превентивно, заполняя его клетку
        if(!checkOneEmptyCell(statePlayer01) && checkOneEmptyCell(statePlayer02))
        {
            int jdx = getEmptyIndex(statePlayer02); 
            field -> setFigure(i, jdx) = figure;
            return 0;
        }
    
        // обнуляем инлекс и массив состояний
        index = 0;                          
        clearArray(statePlayer01);
        clearArray(statePlayer02);

        // тоже самое по вертикали
        j = 0;
        do {
            if(field -> getSymbol(j,i) == figure ) statePlayer01[index] = 1; // Еденица так как нам не важна фигурка
            if(field -> getSymbol(j,i) == enemy  ) statePlayer02[index] = 1; 
            index++;
        } while (++j < FIELD_SIZE);

        // теперь надо проверить состояния предпобеды путем поиска наличия пустой одной клетки 
        // Если у нас выигрышная ситуация а у врага нет тогда делаем ход на свою ячейку
        if(checkOneEmptyCell(statePlayer01) && !checkOneEmptyCell(statePlayer02))
        {
            int jdx = getEmptyIndex(statePlayer01); 
            field -> setFigure(jdx, i) = figure;
            return 0;
        }

        // Если враг в состоянии предпобеды тогда то действуем превентивно, заполняя его клетку
        if(!checkOneEmptyCell(statePlayer01) && checkOneEmptyCell(statePlayer02))
        {
            int jdx = getEmptyIndex(statePlayer02); 
            field -> setFigure(jdx, i) = figure;
            return 0;
        }

        // обнуляем индекс и массив состояний
        index = 0;                          
        clearArray(statePlayer01);
        clearArray(statePlayer02); 

    } while (++i < FIELD_SIZE);


    i = 0; // по диаганали
    do {
        if(field -> getSymbol(i,i) == figure ) statePlayer01[index] = 1; // Еденица так как нам не важна фигурка
        if(field -> getSymbol(i,i) == enemy  ) statePlayer02[index] = 1; 
        index++;
    } while (++i < FIELD_SIZE);

    // теперь надо проверить состояния предпобеды путем поиска наличия пустой одной клетки 
    // Если у нас выигрышная ситуация а у врага нет тогда делаем ход на свою ячейку
    if(checkOneEmptyCell(statePlayer01) && !checkOneEmptyCell(statePlayer02))
    {
        int jdx = getEmptyIndex(statePlayer01); 
        field -> setFigure(jdx, i) = figure;
        return 0;
    }

    // Если враг в состоянии предпобеды тогда то действуем превентивно, заполняя его клетку
    if(!checkOneEmptyCell(statePlayer01) && checkOneEmptyCell(statePlayer02))
    {
        int jdx = getEmptyIndex(statePlayer02); 
        field -> setFigure(jdx, jdx) = figure;
        return 0;
    }

    // обнуляем инлекс и массив состояний
    index = 0;                          
    clearArray(statePlayer01);
    clearArray(statePlayer02);


    i = 0;     //Вторая диагональ
    do {
        if(field -> getSymbol(FIELD_SIZE-i-1,i) == figure ) statePlayer01[index] = 1; // Еденица так как нам не важна фигурка
        if(field -> getSymbol(FIELD_SIZE-i-1,i) == enemy  ) statePlayer02[index] = 1; 
        index++;
    } while (++i < FIELD_SIZE);

    // теперь надо проверить состояния предпобеды путем поиска наличия пустой одной клетки 
    // Если у нас выигрышная ситуация а у врага нет тогда делаем ход на свою ячейку
    if(checkOneEmptyCell(statePlayer01) && !checkOneEmptyCell(statePlayer02))
    {
        int jdx = getEmptyIndex(statePlayer01); 
        field -> setFigure(jdx, i) = figure;
        return 0;
    }

    // Если враг в состоянии предпобеды тогда то действуем превентивно, заполняя его клетку
    if(!checkOneEmptyCell(statePlayer01) && checkOneEmptyCell(statePlayer02))
    {
        int jdx = getEmptyIndex(statePlayer02); 
        field -> setFigure(FIELD_SIZE-jdx-1, jdx) = figure;
        return 0;
    }
    return 1;
}

 int UnitAI::makeMove(Field *field) {

    FIELD_SIZE = field -> getFieldSize();

    //Проверка на предвыигрышные ситуации если есть такие то делаем ход и выходим
    if(!checkPreWinningState(field))
       return 0;
    else {
        // генерация рандомного хода
        int y;
        int x;

        do{
            for (int i = 0; i < 5; i++){
                srand(time(NULL));
                x = (rand()%FIELD_SIZE);
            }
            sleep(1);
            for (int i = 0; i < 3; i++){
                srand(time(NULL)); 
                y = (rand()%FIELD_SIZE); 
            }

            if(field -> getFigure(x,y) == ' ')
                break;

        } while (field -> getFigure(x,y) != ' ');

        if(field -> getFigure(x,y) == ' '){ 
            field -> setFigure(x,y) = figure;
            return 0;
        }
    }
    return 1;
 }