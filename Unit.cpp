
#include "Unit.h"
#include "getch.h"

Unit::Unit(Figure f) {
    figure = f;
};

bool Unit::getState(){
    return winState;
}

int Unit::getFigure(){
    return figure;
}

bool Unit::checkWinState(Field *field) {
    
    int size = field -> getFieldSize();
    
    int winCountPos = size;
 
    for (int i = 0; i < size; i++) {

        // горизонталь
        for (int j = 0; j < size; j++) {
            if (field -> getSymbol(i,j) == figure) {
                winCountPos--;
            }
            if(winCountPos == 0) {
                winState = true;
                break;
            }
        }

        winCountPos = size;

        // вертикаль
        for (int j = 0; j < size; j++) {
            if (field -> getSymbol(j,i) == figure) {
                winCountPos--;
            }
            if(winCountPos == 0) {
                winState = true;
                break;
            }
        }

        winCountPos = size;
    }

    // диагональ
    for (int i = 0; i < size; i++) {
        if (field -> getSymbol(i,i) == figure) {
            winCountPos--;
        }
        if(winCountPos == 0) {
            winState = true;
            break;
        }
    }

    winCountPos = size;

    // другая диагональ
    for (int i = 0; i < size; i++) {
        if (field -> getSymbol(size-i-1,i) == figure) {
            winCountPos--;
        }
        if(winCountPos == 0) {
            winState = true;
            break;
        }
    }
    return winState;
}

int Unit::makeMove(Field *field){

int move = getch();

    switch (move)
    {
        case 49 : if(field -> getFigure(0,0) != ' ')
                        return 1;
                    else{
                        field -> setFigure(0,0) = figure; 
                        return 0;
                    }
                    break;
            
        case 50 : if(field -> getFigure(0,1) != ' ')
                        return 1;
                    else{
                        field -> setFigure(0,1) = figure; 
                        return 0;
                    }
                    break;
        
        case 51 : if(field -> getFigure(0,2) != ' ')
                        return 1;
                    else{
                        field -> setFigure(0,2) = figure; 
                        return 0;
                    }
                    break;
        
        case 52 : if(field -> getFigure(0,3) != ' ')
                        return 1;
                    else{
                        field -> setFigure(0,3) = figure; 
                        return 0;
                    }
                    break;
        case 185 : 
        case 153 : 
        case  81 :
        case 113 : if(field -> getFigure(1,0) != ' ')
                        return 1;
                    else{
                        field -> setFigure(1,0) = figure; 
                        return 0;
                    }
                    break;
        case 134 : 
        case 166 :                
        case 87  : 
        case 119 : if(field -> getFigure(1,1) != ' ')
                        return 1;
                    else{
                        field -> setFigure(1,1) = figure; 
                        return 0;
                    }
                    break;
        case 131 : 
        case 163 : 
        case 69  : 
        case 101 : if(field -> getFigure(1,2) != ' ')
                        return 1;
                    else{
                        field -> setFigure(1,2) = figure; 
                        return 0;
                    }
                    break;
        case 154: 
        case 186 : 
        case 82  : 
        case 114 : if(field -> getFigure(1,3) != ' ')
                        return 1;
                    else{
                        field -> setFigure(1,3) = figure; 
                        return 0;
                    }
                    break;
        case 164 :               
        case 132 : 
        case 65  : 
        case 97  : if(field -> getFigure(2,0) != ' ')
                        return 1;
                    else{
                        field -> setFigure(2,0) = figure; 
                        return 0;
                    }
                    break;
        case 139 :              
        case 171 : 
        case 83  :       
        case 115 : if(field -> getFigure(2,1) != ' ')
                        return 1;
                    else{
                        field -> setFigure(2,1) = figure; 
                        return 0;
                    }
                    break;
        case 146 :                 
        case 178 : 
        case 68  : 
        case 100 : if(field -> getFigure(2,2) != ' ')
                        return 1;
                    else{
                        field -> setFigure(2,2) = figure; 
                        return 0;
                    }
                    break;
        case 176 :                    
        case 144 : 
        case 70  : 
        case 102 : if(field -> getFigure(2,3) != ' ')
                        return 1;
                    else{
                        field -> setFigure(2,3) = figure; 
                        return 0;
                    }
                    break;
        case 143 : 
        case 175 : 
        case 90  : 
        case 122 : if(field -> getFigure(3,0) != ' ')
                        return 1;
                    else{
                        field -> setFigure(3,0) = figure; 
                        return 0;
                    }
                    break;
        case 167 : 
        case 135 : 
        case 88  : 
        case 120 : if(field -> getFigure(3,1) != ' ')
                        return 1;
                    else{
                        field -> setFigure(3,1) = figure; 
                        return 0;
                    }
                    break;
        case 129 : 
        case 161 : 
        case 67  : 
        case 99  : if(field -> getFigure(3,2) != ' ')
                        return 1;
                    else{
                        field -> setFigure(3,2) = figure; 
                        return 0;
                    }
                    break;
        case 188 : 
        case 156 : 
        case 86  : 
        case 118 : if(field -> getFigure(3,3) != ' ')
                        return 1;
                    else{
                        field -> setFigure(3,3) = figure; 
                        return 0;
                    }
                    break;
        default:
            break;
    }

    return 1;
};


