#include "Primary.hpp"

Uis user_interafce, matrix_calculator;

void Uis::uis_initiallizer()
{
    user_interafce.rect = {10, 28, 780, 550};
    DrawRectangleRoundedLines(user_interafce.rect, 0.1, segments, BLACK);

    matrix_calculator.rect = {screenWidth/2.0f - 150, 10, 300, 30};
    DrawRectangleRounded(matrix_calculator.rect, 0.5f, segments, LIGHTGRAY);
    DrawRectangleRoundedLines(matrix_calculator.rect, roundness, segments, BLACK);
}

void Uis::uis_default()
{
    DrawText("MATRIX CALCULATOR",matrix_calculator.rect.x + 35, matrix_calculator.rect.y + 5, font_size, BLACK);
}

void Uis::uis_determinant()
{
    DrawText("MATRIX DETERMINANT",matrix_calculator.rect.x + 35, matrix_calculator.rect.y + 5, font_size, BLACK);
}

void Uis::uis_cofactor()
{
    DrawText("MATRIX CO-FACTOR",matrix_calculator.rect.x + 50, matrix_calculator.rect.y + 5, font_size, BLACK);
}
void Uis::uis_inverse()
{
    DrawText("INVERSE",matrix_calculator.rect.x + 100, matrix_calculator.rect.y + 5, font_size, BLACK);
}
void Uis::uis_linearsystem()
{
    DrawText("LINEAR SYSTEM", matrix_calculator.rect.x + 70, matrix_calculator.rect.y + 5, font_size, BLACK);
}
