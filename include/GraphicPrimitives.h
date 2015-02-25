#pragma once
#include <iostream>
#include <vector>
#include <string.h>

#include "libGraphicInclude.h"

class GraphicPrimitives {
    
public:
    
    static void drawFillRect2D(float x,float y,float width,float height,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un rectangle avec juste ses arrete en (x,y) de largeur width et hauteu height et de couleur r,g,b,a
     *
     */
    static void drawOutlinedRect2D(float x,float y,float width,float height,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine une ligne du point (x1,y1) au point (x2,y2) de couleur r,g,b,a
     *
     */
    static void drawLine2D(float x1,float y1,float x2,float y2,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un triangle qui relit les point 1 2 et 3, de couleur r,g,b,a
     *
     */
    static void drawFillTriangle2D(float x1,float y1,float x2,float y2,float x3,float y3,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un polygone (le dernier sommet rejoindra le premier)
     */
    static void drawOutlinedPolygone2D(std::vector<float> &x,std::vector<float> &y,float r,float g, float b,float a = 1.0f);
    
    /**
     * Dessine un polygone (le dernier sommet rejoindra le premier)
     */
    static void drawFillPolygone2D(std::vector<float> &x,std::vector<float> &y,float r,float g, float b,float a = 1.0f);
    
    /**
     * Ecrit le texte a l'ecran
     */
    static void drawText2D(char * str,float x,float y,float r,float g, float b,float a = 1.0f);
    
    
};

