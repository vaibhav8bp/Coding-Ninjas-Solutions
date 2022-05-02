#include <iostream>
using namespace std;

bool findEmptyLocation(int &current_row, int &current_column, int **sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] == 0)
            {
                current_row = i;
                current_column = j;
                return true;
            }
        }
    }
    return false;
}

bool isSafeInRow(int current_row, int current_column, int **sudoku, int current)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[current_row][i] == current)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInColumn(int current_row, int current_column, int **sudoku, int current)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][current_column] == current)
        {
            return false;
        }
    }
    return true;
}

bool isSafeInBox(int current_row, int current_column, int **sudoku, int current)
{
    int row_factor = current_row - (current_row % 3);
    int column_factor = current_column - (current_column % 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (sudoku[i + row_factor][j + column_factor] == current)
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(int current_row, int current_column, int **sudoku, int current)
{
    return isSafeInRow(current_row, current_column, sudoku, current) && isSafeInColumn(current_row, current_column, sudoku, current) && isSafeInBox(current_row, current_column, sudoku, current);
}

bool solve_sudoku(int **sudoku)
{
    int current_row, current_column;
    if (!findEmptyLocation(current_row, current_column, sudoku))
    {
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (isSafe(current_row, current_column, sudoku, i))
        {
            sudoku[current_row][current_column] = i;
            if (solve_sudoku(sudoku))
            {
                return true;
            }
            sudoku[current_row][current_column] = 0;
        }
    }
    return false;
}

int main()
{
    int **sudoku = new int *[9];

    for (int i = 0; i < 9; i++)
    {
        sudoku[i] = new int[9];
        for (int j = 0; j < 9; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    if (solve_sudoku(sudoku))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    for (int i = 0; i < 9; i++)
    {
        delete[] sudoku[i];
    }
    delete[] sudoku;

    return 0;
}