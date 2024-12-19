#include "Primary.hpp"

Determinant tempor_value[3];

void Determinant::determinant_logic()
{
    for(int a = 0; a < matrix.columns; ++a) // Matrix.columns = 3.
    {
        tempor_value[a].product_top = 1;
        tempor_value[a].product_bottom = 1;
    } // Adding a value to tempor_value so that it can be multiply with the matrix.

    if(is_three_by_three.state == false)
    {
         // Assuming matrix is 2x2 when state is false
         double result = 0;
         double temp[2][2];

        // Fill temp with values from box for a 2x2 matrix calculation 
         for (int i = 0; i < 2; ++i)
         {
             for (int j = 0; j < 2; ++j)
                 {
                     temp[i][j] = box[i][j].numbersArray;
                 }
        }

         // Calculate determinant: ad - bc
         result = (temp[0][0] * temp[1][1]) - (temp[0][1] * temp[1][0]);

         // Store in output box and print for verification
         output_box_value.two_two = result;
         std::cout << "2x2 Determinant = " << output_box_value.two_two << std::endl;
    }
    else if(is_three_by_three.state == true)
    {
        int clk;
        for(int a = 0; a < matrix.columns; ++a)
        {
            tempor_value[a].pivod = box[a][0].numbersArray;
            clk = 0;
            
            std::cout << "Tempor_value[" << a << "] = " << tempor_value[a].pivod << " = box[" << a << "][0].numbersArray = " << box[a][0].numbersArray << std::endl; // // For troubleshooting

            for(int u = 1; u < matrix.columns; ++u )
            {
                for(int t = 0; t < matrix.columns; ++t)
                {
                    if( t != a && clk == 0)
                    {
                        tempor_value[a].product_top *= box[t][u].numbersArray;
                        clk = 2;
                        std::cout << "product_top box[" << t << "]" << "[" << u << "] = " << box[t][u].numbersArray << std::endl; // For troubleshooting
                    }
                    else if ( t != a )
                    {
                        tempor_value[a].product_bottom *= box[t][u].numbersArray;
                        clk -= 1;
                        std::cout << "product_bottom box[" << t << "]" << "[" << u << "] = " << box[t][u].numbersArray << std::endl; // For troubleshooting
                    }
                }   
            }

            std::cout << "TEMP VALUE product_top [" << a << "]= " << tempor_value[a].product_top << std::endl; // For troubleshooting.
            std::cout << "TEMP VALUE product_bottom [" << a << "]= " << tempor_value[a].product_bottom << std::endl <<std::endl; //For troubleshooting.
        }
        output_box_value.three_three = 0;
        for(int a = 0; a < 3; ++a)
        {
            if( a == 1 ) 
            {                
                output_box_value.three_three -= (tempor_value[a].pivod * (tempor_value[a].product_top - tempor_value[a].product_bottom));
            }
            else
            {
                output_box_value.three_three += (tempor_value[a].pivod * (tempor_value[a].product_top - tempor_value[a].product_bottom));
            }
        
        std::cout << "Stage [" << a << "] output_box_value.three_three = " << output_box_value.three_three << std::endl;

        }
    }
    std::cout << "OUTPUT_BOX_VALUE = " << output_box_value.three_three << std::endl << std::endl; // For troubleshooting.
}

Result output_box;
Result::determinant_result output_box_value;

void Result::designating_output_box_and_draw()
{
    float offset_x = 100, offset_y = 150;
    output_box.rect = {screenWidth/2.0f, screenHeight/2.0f + offset_y, default_input_box_size.x * 4, default_input_box_size.y };
    DrawRectangleRounded(output_box.rect, roundness, segments, LIGHTGRAY);
    DrawText( "Determinant result: " , screenWidth/2 - 210, screenHeight/2 + 165, font_size, BLACK);
    if(is_three_by_three.state == false)
    {
    DrawText(TextFormat("%2.2f",output_box_value.two_two), output_box.rect.x + 15, output_box.rect.y + 13, number_size, BLACK);
    }
    else if(is_three_by_three.state == true )
    {
    DrawText(TextFormat("%2.2f", output_box_value.three_three), output_box.rect.x + 8, output_box.rect.y + 13, number_size, BLACK);
    }
}