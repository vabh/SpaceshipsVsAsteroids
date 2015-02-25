#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Grid.h"
#include "Spaceship.h"
#include "Asteroid.h"
#include "Bullet.h"

class MyGraphicEngine:public GraphicEngine {
    
    Grid * grid;
    std::vector<Spaceship *> *ships;
    std::vector<Asteroid *> *asteroids;
    std::vector<Bullet *> *bullets;
    

public:
    
    MyGraphicEngine(Grid * grid_, std::vector<Spaceship *> *ships_, std::vector<Asteroid *> *asteroids_,
                    std::vector<Bullet *> *bullets_):
        grid(grid_),
        ships(ships_),
        asteroids(asteroids_),
        bullets(bullets_)
        {}
        
    virtual void Draw();
    virtual void reshape(int w, int h);
};