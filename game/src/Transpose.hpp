#pragma once
#ifndef Transpose_hpp
#define Transpose_hpp

#include "Primary.hpp"

class Transpose : protected RECTANGLE
{
    public:
    double number;
    void transpose_logic();
    void transpose_draw();
    protected:
};

extern Transpose transpose_value[3][3];

#endif