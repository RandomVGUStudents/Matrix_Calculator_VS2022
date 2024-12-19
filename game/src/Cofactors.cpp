#include "Primary.hpp"

Cofactor temp_value[3][3], cofactor_value[3][3];

void Cofactor::cofactor_logic() // Co factor logic.
{    

    for( int a = 0; a < matrix.columns; ++a ) // To give all temp_value[][]. an initial value of multiplication.
    {
        for( int b = 0; b < matrix.rows; ++b )
        {
            temp_value[a][b].productTop = 1;
            temp_value[a][b].productBottom = 1;
        }
    }
    int clk1;
    if( is_three_by_three.state )
    {
        for( int a = 0; a < matrix.columns; ++a )
        {
            for( int b = 0; b < matrix.rows; ++b )
            {
                temp_value[a][b].pivot = box[a][b].numbersArray;
                clk1 = 0;
                for( int t = 0; t < matrix.columns; ++t )
                {
                    if( t != a )
                    {
                        for( int u = 0; u < matrix.rows; ++u )
                        {
                            if( u != b && clk1 == 0)
                            {
                                temp_value[a][b].productTop *= box[t][u].numbersArray;
                                clk1 = 2;
                            }
                            else if ( u != b )
                            {
                                temp_value[a][b].productBottom *= box[t][u].numbersArray;
                                clk1 -= 1;
                            }}}}

                if( (a + b)%2 == 0 )
                {cofactor_value[a][b].number = (temp_value[a][b].productTop - temp_value[a][b].productBottom);}
                else
                {cofactor_value[a][b].number = -1 * (temp_value[a][b].productTop - temp_value[a][b].productBottom);}

                // Terminal Trouble shotting.
                //std::cout << "cofactor_value[" << a << "][" << b << "].number = " << cofactor_value[a][b].number << std::endl;
            }
        }
    }
    else if( !is_three_by_three.state )
    {
        for( int a = 0; a < matrix.columns; ++a )
        {
            for( int b = 0; b < matrix.rows; ++b )
            {
                for( int t = 0; t < matrix.columns; ++t )
                {
                    if( t != a )
                    {
                        for( int u = 0; u < matrix.rows; ++u )
                        {
                            if( u != b )
                            {
                                if( (a + b) == 1)
                                {
                                    cofactor_value[a][b].number = -1* box[t][u].numbersArray; 
                                }
                                else
                                {
                                    cofactor_value[a][b].number = 1* box[t][u].numbersArray; 
                                }}}}}}}}}
                            
void Cofactor::cofactor_draw() 
{
    float offset_y = 80, offset_x = 30;
    for(int t = 0; t < matrix.columns; ++t)
    { 
        float offset_y_value = 1;
        for(int u = 0; u < matrix.rows; ++u)
        {
            cofactor_value[t][u].rect = {screenWidth/2.0f + offset_x, 250 + offset_y * offset_y_value, default_input_box_size.x, default_input_box_size.y}; // Matrix Boxes
            offset_y_value++;
        }
        offset_x += 90;
    }   
    int clk2 = 0;
    for(int t = 0; t < matrix.columns; ++t)
    {
        for(int u = 0; u < matrix.columns; ++u)
        {
            DrawRectangleRounded(cofactor_value[t][u].rect, roundness, segments, LIGHTGRAY);
            if( !box[t][u].inputNumber.empty())
            {
                clk2++;
            }
            
        }
    }
    for(int t = 0; t < matrix.columns; ++t)
    {
        for(int u = 0; u < matrix.columns; ++u)
        {
            if(clk2 == matrix.columns*matrix.columns)
            {
                DrawText(TextFormat("%2.1f",cofactor_value[t][u].number), cofactor_value[t][u].rect.x + 8, cofactor_value[t][u].rect.y + 13, number_size, BLACK);
            }
        }
    }
}
