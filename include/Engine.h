#pragma once
#include <iostream>
#include "ControlEngine.h"
#include "GameEngine.h"
#include "GraphicEngine.h"
#include "libGraphicInclude.h"
#include "GraphicPrimitives.h"

//singleton
class Engine {
public:
    
    Engine(int argc, char * argv[],int width = 800,int height = 600,char * title = "Asteroids and Spaceships");
    
    //these methods are in the header file because you have to see that the previous Engines are deleted...
    void setControlEngine(ControlEngine* crtE){
        delete crtE_;
        crtE_ = crtE;
    }
    void setGameEngine(GameEngine* gmE){
        delete gmE_;
        gmE_ = gmE;
    }
    void setGraphicEngine(GraphicEngine* grE){
        delete grE_;
        grE_ = grE;
    }
    
    void start();
    
    static ControlEngine * crtE_;
    static GameEngine * gmE_;
    static GraphicEngine * grE_;
    
private:
    void controlBoot();
    void graphicBoot();
    void gameBoot();
    
};