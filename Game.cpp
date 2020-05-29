#include "Game.h"

void Game::drawField(){
    for (int i = 0; i < field -> getFieldSize() ; i++)
    {
        std::cout << "\t\t " ;
        for (int j = 0; j < field -> getFieldSize(); j++)
        {
            std::cout << field -> getFigure(i,j) << (j < field -> getFieldSize()-1 ? " | " : "\n"); 
        }
        std::cout << "\t\t" ;
        if (i < field -> getFieldSize()-1){
            for (int i = 0; i < field -> getFieldSize(); i++)
            {
                std::cout << (i == field -> getFieldSize()-1 ? "---" : "----" );
            }
        }
        std::cout << std::endl;    
    }  
}

void Game::drawField(char figure){
    for (int i = 0; i < field -> getFieldSize() ; i++)
    {
        std::cout << "\t\t " ;
        for (int j = 0; j < field -> getFieldSize(); j++)
        {
            std::cout << 

                (field -> getFigure(i,j) == figure ? field -> getFigure(i,j) : ' ')

                      << (j < field -> getFieldSize()-1 ? " | " : "\n"); 
        }
        std::cout << "\t\t" ;
        if (i < field -> getFieldSize()-1){
            for (int i = 0; i < field -> getFieldSize(); i++)
            {
                std::cout << (i == field -> getFieldSize()-1 ? "---" : "----" );
            }
        }
        std::cout << std::endl;    
    }  
}

void Game::drawLogo() {
    std::string pic[3] = {"█░░ ▀ █▄░█ █▀▄ █░█     ▄▀▀░ ▄▀▄ █▄░▄█ █▀▀ ▀   █░█ ▄▀▄     ▄▀▄ ▀\n",
                          "█░▄ █ █░▀█ █░█ ▄▀▄     █░▀▌ █▀█ █░█░█ █▀▀     ▄▀▄ █░█     █▀█ █\n", 
                          "▀▀▀ ▀ ▀░░▀ ▀▀░ ▀░▀     ▀▀▀░ ▀░▀ ▀░░░▀ ▀▀▀ ▀   ▀░▀ ░▀░     ▀░▀ ▀\n"}; 
    for(std::string s : pic)
        std::cout << s;
 }

void Game::drawMenu(){
    std::cout << "Please chouse game: " << std::endl;    
        std::cout << "\t 1. Ai vs Ai < " << std::endl;
        std::cout << "\t 2. PvP      " << std::endl;
        std::cout << "\t 3. PvE      " << std::endl;
        std::cout << "\t 4. How to play ?       " << std::endl;
        std::cout << "\t 0. Exit                " << std::endl;
}

void Game::startGameMenu(){

    int gameTypeSelection = 0;

    do {
        system("clear");  
        drawLogo();
        drawMenu(); 

        std::cout << "$ "; std::cin >> gameTypeSelection; 

        if (gameTypeSelection == 1)
        {
            system("clear");  
            drawLogo();
            std::cout << "\t > Game: Comp vs Comp < \n"<< std::endl;
            
            choiceFieldSize();

            gameLoopCompVsComp();
        }
        else if(gameTypeSelection == 2)
        {
            system("clear");  
            drawLogo();
            std::cout << " > Wish your have some fun < " << std::endl; 
            
            choiceFieldSize();

            gameLoopPvP(); 

        } 
        else if(gameTypeSelection == 3)
        {
            system("clear");  
            drawLogo();
            std::cout << " > Challenge accepted < " << std::endl; 
            
            choiceFieldSize();

            gameLoopPvE();
        } 
        else if(gameTypeSelection == 4)
        {
            system("clear");  
            drawLogo();
            std::cout << "Input character equals this cell:\n" << std::endl;

            std::string rulse[7] = { "\t 1 | 2 | 3       1 | 2 | 3 | 4 ",
                                     "\t-----------     ---------------",
                                     "\t q | w | e   or  q | w | e | r ",
                                     "\t-----------     ---------------",
                                     "\t a | s | d       a | s | d | f ",
                                     "                \t ---------------",
                                     "                \t z | x | c | v " };
            for(std::string s : rulse) 
                std::cout << s << std::endl; 
            
            std::cout << "\n$: If you want stop game input \"Q\": [shift] + [q]" << std::endl;    
            std::cout << "\n Input any character to return main menu,";
            std::cout << "\n or input \"1\" to start PvE game: $: "; std::cin >> gameTypeSelection; 
            
            if(gameTypeSelection == 1){
                 choiceFieldSize();
                 gameLoopPvE();
            }
               
        }
        else if(gameTypeSelection == 0)
        {
            system("clear");
            drawLogo();
            std::cout << " > Exit Game <" << std::endl;
            sleep(1);
            isGame = false;
            return;
        }

        endGameMenu();

    } while (gameTypeSelection != 1 || gameTypeSelection != 2 || gameTypeSelection != 3 || gameTypeSelection != 4 || isGame);  
}

void Game::choiceFieldSize() {

    system("clear");
    drawLogo();
    
    std::cout << "\nwhat field size you prefer for game?:\n" << std::endl;
    std::cout << "\t3. 3x3" << std::endl;
    std::cout << "\t4. 4x4" << std::endl;

    int fSize;
    std::cout << "$: "; std::cin >> fSize;
    if(fSize == 3 || fSize == 4 )
        field -> setFieldSize(fSize);
    else
        field -> setFieldSize(3);

    field -> initField();    
}

void Game::endGameMenu() {

    system("clear");
    drawLogo();

    if (winner == X){
        std::cout << "\nWinner X" << std::endl;
        drawField('X');

    }
    if (winner == O){
        std::cout << "\nWinner O" << std::endl;
        drawField('O');

    }
    if (gameOver) {
        std::cout << "\nGAME OVER: impossible to finish the game" << std::endl;
        drawField();
    }
    
    std::cout << "do you wanna paly again? (1) yes, (0) exit: \n $: ";
    
    int choice = 0;
    
    std::cin >> choice;
    
    if (choice == 1)
    {
        initGame(); 
        startGameMenu();     
    }else{
        system("clear");
        drawLogo();
        std::cout << " > Exit Game <" << std::endl;
        sleep(1);
        isGame = false;
        return;
    }
}

void Game::gameLoopPvE() {

    int timer = 0;
    int maxPosibleStep = field -> getFieldSize() * field -> getFieldSize();
 
    do{ 
        do{
            system("clear");
            drawLogo();
            std::cout << "\t > Game: Challenge with AI < \n" << timer++ << std::endl;      
           
            drawField();

            std::cout << "Yuor turn (X): "; 
            if (!human_one -> makeMove(field)) 
                break;   
        } while (human_one -> makeMove(field));

        maxPosibleStep--;

        human_one -> checkWinState(field);

        do{
            if(comp_two -> getState())
                break;

            system("clear");
            drawLogo();
            std::cout << "\t > Game: PvP < \n" << timer++ << std::endl;     
            drawField();
            
            std::cout << "My turn is (O): ";
            sleep(1);
            if (!comp_two -> makeMove(field))
                break;
        } while (comp_two -> makeMove(field));

        maxPosibleStep--;
        
        comp_two -> checkWinState(field);

        if (human_one -> getState() || comp_two-> getState()  ) {
           // сотяоние одной из пообед (true | false) & (false | true)

            if(human_one -> getState())
                winner = (Figure) human_one -> getFigure();
            if(comp_two -> getState()) 
                winner = (Figure) comp_two -> getFigure();
            isGame = false; 
        }

        if(!maxPosibleStep) {
            isGame = false;
            gameOver = true;
        }

    } while (isGame);
}

void Game::gameLoopPvP() {

    int timer = 0;
    int maxPosibleStep = field -> getFieldSize() * field -> getFieldSize();
 
    do{ 
        do{
            system("clear");
            drawLogo();
            std::cout << "\t > Game: PvP < \n" << timer++ << std::endl;      

            drawField();

            std::cout << "Player X: "; 
            if (!human_one -> makeMove(field)) 
                break;   
        } while (human_one -> makeMove(field));

        maxPosibleStep--;

        human_one -> checkWinState(field);

        do{
            if(human_one -> getState())
                break;

            system("clear");
            drawLogo();
            std::cout << "\t > Game: PvP < \n" << timer++ << std::endl;     
            drawField();
            
            std::cout << "Player O: ";
            if (!human_two -> makeMove(field))
                break;
        } while (human_two -> makeMove(field));

        maxPosibleStep--;
        
        human_two -> checkWinState(field);

        if (human_one -> getState() || human_two-> getState()  ) {
           // сотяоние одной из  обед (true | false) & (false | true)

            if(human_one -> getState())
                winner = (Figure) human_one -> getFigure();
            if(human_two -> getState()) 
                winner = (Figure) human_two -> getFigure();
            isGame = false; 
        }

        if(!maxPosibleStep) {
            isGame = false;
            gameOver = true;
        }

    } while (isGame);
}

void Game::gameLoopCompVsComp() {

    int timer = 0;
    int maxPosibleStep = field -> getFieldSize() * field -> getFieldSize();
 
    do{ 
        do{
            system("clear");
            drawLogo();
            std::cout << "\t > Game: Comp vs Comp < \n" << timer++ << std::endl;      

            drawField();

            std::cout << "Player (X): "; 
            sleep(1);

            if (!comp_one -> makeMove(field)) 
                break;   
        } while (comp_one -> makeMove(field));

        maxPosibleStep--;

        comp_one -> checkWinState(field);

        do{
            if(comp_two -> getState())
                break;

            system("clear");
            drawLogo();
            std::cout << "\t > Game: Comp vs Comp < \n" << timer++ << std::endl;
            drawField();
            
            std::cout << "Player (O): ";
            sleep(1);
            
            if (!comp_two -> makeMove(field))
                break;
        } while (comp_two -> makeMove(field));

        maxPosibleStep--;
        
        comp_two -> checkWinState(field);

        if (comp_one -> getState() || comp_two-> getState()  ) {
           // сотяоние одной из пообед (true | false) & (false | true)

            if(comp_one -> getState())
                winner = (Figure) comp_one -> getFigure();
            if(comp_two -> getState()) 
                winner = (Figure) comp_two -> getFigure();
            isGame = false; 
        }

        if(!maxPosibleStep) {
            isGame = false;
            gameOver = true;
        }

    } while (isGame);
}