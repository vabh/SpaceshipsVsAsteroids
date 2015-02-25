#pragma once
#include "Engine.h"
#include "Grid.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Bullet.h"

#include <random>

class MyControlEngine:public ControlEngine {
    
    Grid * grid;
    std::vector<Spaceship *> *ships;
    std::vector<Asteroid *> *asteroids;
    std::vector<Bullet *> *bullets;

public:
    MyControlEngine(Grid * grid_, std::vector<Spaceship *> *ships_, std::vector<Asteroid *> *asteroids_,
    				std::vector<Bullet *> *bullets_):
    	grid(grid_),
    	ships(ships_),
    	asteroids(asteroids_),
    	bullets(bullets_)
    {}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
    virtual void KeyboardCallback(unsigned char key,int x, int y);

    int get_random_number(int a, int b);
};