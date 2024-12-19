#include "Primary.hpp"

State button[6]; //Mode selection.
State btn;


void State::draw(float a, float b, float x, float y, const int n, const int state_determine, const int name_enable, const char* name)
{

    button[n].rect = { a, b, x, y };
    DrawRectangleRounded(button[n].rect, roundness, segments, LIGHTGRAY);
    if (name_enable == 1)
    {
        DrawText(name, button[n].rect.x + 25, button[n].rect.y + 15, font_size, BLACK);
    }
    if (CheckCollisionPointRec(GetMousePosition(), button[n].rect)) button[n].mouse_over_box = true;
    else if (!CheckCollisionPointRec(GetMousePosition(), button[n].rect)) { button[n].mouse_over_box = false; }

    if (n == 1)
    {
        DrawTexture(Back_Arrow, button[n].rect.x, button[n].rect.y, WHITE);
    } // Draw back button texture.

    if (button[n].mouse_over_box == true)
    {
        DrawRectangleRounded(button[n].rect, roundness, segments, TRANSPARENT_BEIGE);
        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
        {
            btn.state = state_determine;
        }
    }
}

void State::cofact_switch()
{
    btn.draw(screenWidth / 2 - 200, screenHeight / 2 + 190, 155, 50, 5, 3, 1, "Disabled");
    DrawText("Transpose:", screenWidth / 2 - 330, screenHeight / 2 + 205, font_size, BLACK);
}

void State::trans_switch()
{
    btn.draw(screenWidth / 2 - 200, screenHeight / 2 + 190, 155, 50, 6, 31, 1, "Enabled");
    DrawText("Transpose:", screenWidth / 2 - 330, screenHeight / 2 + 205, font_size, BLACK);
}

void State::back()
{
    btn.draw(20, 40, 50, 50, 1, 1, 0, "Back");
    DrawText("<", 36, 47, font_size + 20, BLACK); // Macro Adjustments.
}

void State::selection()
{
    btn.draw(screenWidth / 2 - 100, screenHeight / 2 - 200, 200, 50, 2, 2, 1, "Determinant");
    btn.draw(screenWidth / 2 - 100, screenHeight / 2 - 130, 200, 50, 3, 3, 1, "Co_factor");
    btn.draw(screenWidth / 2 - 100, screenHeight / 2 - 60, 200, 50, 4, 4, 1, "Inverse");
    btn.draw(screenWidth / 2 - 100, screenHeight / 2 + 10, 200, 50, 5, 5, 1, "Linear_system");
}

