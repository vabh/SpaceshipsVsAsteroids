#include <iostream>
#include "Engine.h"

#include "MyGraphicEngine.h"
#include "MyGameEngine.h"
#include "MyControlEngine.h"


int main(int argc, char * argv[])
{
    
    Engine e(argc, argv);

    int row = 3;
    int column = 10;
    
    std::cout << std::endl << "Welcome!\n";
    std::cout << std::endl << "Enter row and column number to set the size of the board.\n";
    std::cout << std::endl << "To choose a spacechip press the numbers:\n";
    std::cout << std::endl << "1. Red Spaceship [Moderately Fast and Strong]";
    std::cout << std::endl << "2. Green Spaceship [Slow and Powerful]";
    std::cout << std::endl << "1. Blue Spaceship [Very Fast but weak]";
    std::cout << std::endl << "To launch a new asteroid wave, press the spacebar";

    std::cout << "\nEnter rows: " << std::endl;
    std::cin >> row;
    std::cout << "Enter columns: " << std::endl;
    std::cin >> column;

    //default values if input is invalid
    if(row < 1 || row > 10)
        row = 3;
    if(column < 1 || column > 15)
        column = 10;

    Grid grid(row, column, 0.5f);
    std::vector<Spaceship *> ships;
    std::vector<Asteroid *> asteroids;
    std::vector<Bullet *> bullets;
    

    GraphicEngine * ge = new MyGraphicEngine(&grid, &ships, &asteroids, &bullets);
    GameEngine * gme = new MyGameEngine(&grid, &ships, &asteroids, &bullets);
    ControlEngine * ce = new MyControlEngine(&grid, &ships, &asteroids, &bullets);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    
    return 0;
}
