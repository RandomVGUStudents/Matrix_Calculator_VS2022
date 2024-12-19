#pragma once 
#ifndef Inverse_hpp
#define Inverse_hpp
#include "Primary.hpp"

class Inverse : protected RECTANGLE
{
    public:
    double number;
    void inverse_logic();
    void inverse_function(double determinant);
    void inverse_draw();
};
#endif
