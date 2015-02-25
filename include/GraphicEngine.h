#pragma once

#include "GraphicPrimitives.h"

class GraphicEngine {
    
    
public:
    
    virtual void Draw();
    virtual void reshape(int width, int height);
};