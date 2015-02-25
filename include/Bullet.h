#pragma once
#include "GraphicPrimitives.h"

class Bullet {
    
    float posX, posY;
    float width = 0.02, height = 0.02;
    float r = 0.0f, g = 0.0f, b = 0.0f;

    float speed;

    int life = 1;
    int damage;

public:
    Bullet(float posX_, float posY_, int damage_);

    void draw();
    void move();

    float get_posX();
    float get_posY();
    float get_width();
    float get_height();

    int get_damage();
};