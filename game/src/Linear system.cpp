
#include "Primary.hpp"

// Solving the linear system
void LinearSystem::LS_logic()
{
    vector <double> tempB;
    vector<vector<double>> tempA;

    bool fillAll = true;
    for (int j = 0; j < matrix.columns; j++) {
        vector<double> v;
        for (int i = 0; i < matrix.columns; i++) {
            if (!box[i][j].numberEntered) {
                fillAll = false;
            }
            v.push_back(box[i][j].numbersArray);
        }
        tempA.push_back(v);
    }

    for (int i = 0; i < matrix.columns; i++) {
        if (!linear_value[0][i].numberEntered) {
            fillAll = false;
        }
        tempB.push_back(linear_value[0][i].numbersArray);
    }
    if (!fillAll || matrix.columns == 0)
    {
        cout << "Please provide valid inputs." << endl;
        return;
    }

    A.clear(); B.clear();
    solution.clear();
    A = tempA; B = tempB;

    // Ensure the right size of matrix
    if (A.size() != A[0].size() || B.size() != A.size())
    {
        cout << "Matrix must be square and match the size of constants." << endl;
        return;
    }

    // Number of equations

    // Augmented Matrix [ A | B ]
    vector<vector<double>> augmented(matrix.columns, vector<double>(matrix.columns + 1));
    for (int i = 0; i < matrix.columns; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            augmented[i][j] = A[i][j];
        }
        augmented[i][matrix.columns] = B[i];
    }

    // Gaussian elimination
    for (int i = 0; i < matrix.columns; i++)
    {
        double pivot = augmented[i][i];
        if (pivot == 0)
        {
            cout << "The matrix is singular -> can't be solved." << endl;
            return;
        }

        for (int j = i; j <= matrix.columns; j++)
        {
            augmented[i][j] /= pivot;
        }

        for (int k = 0; k < matrix.columns; k++)
        {
            if (k != i)
            {
                double factor = augmented[k][i];
                for (int j = i; j <= matrix.columns; j++)
                {
                    augmented[k][j] -= factor * augmented[i][j];
                }
            }
        }
    }

    // Extract the solution
    solution.resize(matrix.columns);
    for (int i = 0; i < matrix.columns; i++) {
        solution[i] = augmented[i][matrix.columns];
    }

    // Output for debugging
    cout << "Solution:\n";
    for (int i = 0; i < matrix.columns; ++i)
    {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }
}

// Method to draw the system (matrix, constants, and solution)
void LinearSystem::draw()
{
    if (A.empty() || B.empty()) {
        cout << "The system has not been set. Nothing to draw." << endl; // For troubleshooting linear system output box.
        return;
    }

    // Starting position of the matrix
    float offset_y = 80, offset_x = 30;
    float cell_width = 100, cell_height = 50;
    float start_x = 100, start_y = 100;

    // Draw solution if available
    if (!solution.empty()) {
        float solution_start_x = start_x + offset_x;
        float solution_start_y = start_y + offset_y + (A.size() + 1) * cell_height;

        for (int i = 0; i < solution.size(); ++i) {
            Rectangle rectSolution = { solution_start_x + i * cell_width + 20 * i + 20 * i, solution_start_y + 20 + 20, cell_width, cell_height };
            DrawRectangleRounded(rectSolution, roundness, segments, LIGHTGRAY);
            DrawText(TextFormat("x%d = %.2lf", (int)i + 1, solution[i]), rectSolution.x + 10, rectSolution.y + 15, 20, BLACK);
        }
    }
    else {
        // If no solution, display a message
        float nosolution_x = start_x + offset_x;
        float nosolution_y = start_y + offset_y + (A.size() + 1) * cell_height;
        DrawText("Solution is not available.", nosolution_x, nosolution_y, 20, RED);
    }
}
