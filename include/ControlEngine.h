#pragma once
#include <iostream>
#include "libGraphicInclude.h"

class ControlEngine {
    
public:
    virtual void KeyboardCallback(unsigned char key,int x, int y);
    
    virtual void KeyboardReleaseCallback(unsigned char key,int x, int y);
    
    virtual void specialCallback(int key,int x, int y);
    
    virtual void MouseCallback(int button, int state, int x, int y);
    
    virtual void MotionCallback(int x, int y);
    
    virtual void PassiveMotionCallback(int x, int y);
    
    virtual void MouseEntry(int state);
    
    virtual void JoystickCallback(unsigned int buttonMask,
                          int x, int y, int z);
};