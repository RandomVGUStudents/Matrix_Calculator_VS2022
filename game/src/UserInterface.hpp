#pragma once

#ifndef UserInterface_hpp
#define UserInterface_hpp

#include "MatrixArray.hpp"

class Uis : protected RECTANGLE
{    
    public:
    void uis_initiallizer();
    void uis_default();
    void uis_determinant();
    void uis_cofactor();
    void uis_inverse();
    void uis_linearsystem();
};

#endif
