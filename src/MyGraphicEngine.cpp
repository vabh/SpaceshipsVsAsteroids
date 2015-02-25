#include "MyGraphicEngine.h"

void MyGraphicEngine::Draw(){
    
    std::string s = std::to_string(grid->get_score());
    char *score = (char *)s.c_str();

    std::string msg = "Points: ";
    char *message = (char*)msg.c_str();
    GraphicPrimitives::drawText2D(message, -0.15f, -1.f, 1.f, 1.f, 1.f);
    GraphicPrimitives::drawText2D(score, 0.f, -1.f, 1.f, 1.f, 1.f);

    //drawing grid
    grid->draw();
    
    //drawing ship
    for (int i = 0; i < ships->size(); i++) {
        (*ships)[i]->draw();
    }

    //drawing bullets
    for (int i = 0; i < bullets->size(); i++) {
        (*bullets)[i]->draw();
    }

    //drawing asteroids
    for (int i = 0; i < asteroids->size(); i++) {
        (*asteroids)[i]->draw();
    }
}

// handle window resize
void MyGraphicEngine::reshape(int w, int h){
    grid->set_dimension(w, h);
}