#pragma once
#include "GraphicPrimitives.h"

class Asteroid {
    
    float posX, posY;
    float width, height;
    float boundary_left, boundary_right;
    float r = 0.5, g = 0.2, b = 0.2;

    float speed;
    float speedY;
    int life;

public:
    Asteroid(float posX_, float posY_, float speedY_);
    
    void draw();
    void move();

    float get_posX();
    float get_posY();
    float get_width();
    float get_height();

    int strike(int d);  
    int get_life();
    void set_life(int l);
};