#include "Transpose.hpp"

Transpose transpose_value[3][3];

void Transpose::transpose_logic()
{
    for( int a = 0; a < matrix.columns; a ++ )
    {
        for( int b = 0; b < matrix.rows; b ++ )
        {
            if( (a * 10 + b) != (b * 10 + a) )
            {
                transpose_value[b][a].number = cofactor_value[a][b].number;
            }
            else
            {
                transpose_value[a][b].number = cofactor_value[a][b].number;
            }
        }
    }
}

void Transpose::transpose_draw() 
{
    float offset_y = 80, offset_x = 30;
    for(int t = 0; t < matrix.columns; ++t)
    { 
        float offset_y_value = 1;
        for(int u = 0; u < matrix.rows; ++u)
        {
            transpose_value[t][u].rect = {screenWidth/2.0f + offset_x, 250 + offset_y * offset_y_value, default_input_box_size.x, default_input_box_size.y}; // Matrix Boxes
            offset_y_value++;
        }
        offset_x += 90;
    }

    // To check if all of the input boxes are filled in.
    // -------------------------------------------------
    int clk2 = 0;
    for(int t = 0; t < matrix.columns; ++t)
    {
        for(int u = 0; u < matrix.columns; ++u)
        {
            DrawRectangleRounded(transpose_value[t][u].rect, roundness, segments, LIGHTGRAY);
            if( !box[t][u].inputNumber.empty())
            {
                clk2++;
            }
        }
    }
    // -------------------------------------------------

    for(int t = 0; t < matrix.columns; ++t)
    {
        for(int u = 0; u < matrix.columns; ++u)
        {
            if(clk2 == matrix.columns*matrix.columns)
            {
                DrawText(TextFormat("%2.1f",transpose_value[t][u].number), transpose_value[t][u].rect.x + 8, transpose_value[t][u].rect.y + 13, number_size, BLACK);
            }
        }
    }
}