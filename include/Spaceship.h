#pragma once
#include "GraphicPrimitives.h"

class Spaceship {
    
    float posX, posY;
    float width, height;
    float boundary_top, boundary_bottom;
    float r = 0, g = 0, b = 0;
    
    float speed;
    int power;
    int type;
    int fire_frequency;
    int fire_wait;

    void set_parameters();

public:
    Spaceship(float posX_, float posY_, float b_r, float b_c, float cell_distance, int type);
    
    void draw();
    void move();

    float get_posX();
    float get_posY();
    float get_width();
    float get_height();
    
    bool shoot();
    int get_power();
};