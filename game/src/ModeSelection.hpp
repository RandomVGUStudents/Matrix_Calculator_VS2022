#pragma once
#ifndef ModeSelection_hpp
#define ModeSelection_hpp

#include "Primary.hpp"

extern Texture2D Back_Arrow;

class State : protected RECTANGLE //To define calculator state.
{
    protected:
    public:
    int state = 1; //default = 1; determinate = 2; Co Factor = 3; adjoint = 4; linear system = 5;
    bool button_state;
    bool mouse_over_box = false;

    void cofact_switch();
    void trans_switch();
    void back();
    void selection();
    void draw( float a , float b, float x, float y,const int n, const int state_determine, const int name_enable, const char* name); //instruction to use void draw(): rectangle position x, rectangle position y, rect size width, rect size hight, rect width, button designation number, name_enable 1 or 0, text

};

extern State btn;

#endif
