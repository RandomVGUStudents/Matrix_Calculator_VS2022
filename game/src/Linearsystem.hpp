#pragma once

#ifndef Linearsystem_hpp
#define Linearsystem_hpp

#include "Primary.hpp"

using namespace std;

class LinearSystem {

public:
    // Process to solve the system only
    void LS_logic();

    // Draw the system (matrix, constants, and solution)
    void draw();

private:
    vector<vector<double>> A; // Coefficient matrix (2D vector)
    vector<double> B;         // Constants vector
    vector<double> solution;  // Solution vector
};

#endif