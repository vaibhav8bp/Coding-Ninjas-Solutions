#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols)
{
    int i, j, start_row = 0, start_column = 0, end_row = nRows - 1, end_column = nCols - 1;
    while (start_row <= end_row && start_column <= end_column)
    {
        for (j = start_column; j <= end_column; j++)
        {
            cout << input[start_row][j] << " ";
        }
        start_row++;
        for (j = start_row; j <= end_row; j++)
        {
            cout << input[j][end_column] << " ";
        }
        end_column--;
        for (j = end_column; j >= start_column; j--)
        {
            cout << input[end_row][j] << " ";
        }
        end_row--;
        for (j = end_row; j >= start_row; j--)
        {
            cout << input[j][start_column] << " ";
        }
        start_column++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}