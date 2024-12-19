#pragma once

#ifndef Determinants_hpp //header guard to prevent re-initiate of the file multiple times.
#define Determinants_hpp

// Custom headers
#include "Primary.hpp"

class Determinant
{
    private:
    public:
    
    void determinant_logic();
    double product_top, product_bottom, pivod;
};

class Result : protected RECTANGLE
{
    public:
    void designating_output_box_and_draw(); // Defining output box and drawing it.
    struct determinant_result
    {
        double two_two, three_three;
    };
};

extern Result::determinant_result output_box_value;

#endif
