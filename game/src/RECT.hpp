#pragma once

#include <raylib.h>
#include <string>
#include <vector>
#include <iostream>

class RECTANGLE
{
    protected:
    Vector2 position;
    Vector2 size;
    Rectangle rect = {position.x, position.y, size.x, size.y};
};
