#include <iostream>
#include <climits>
using namespace std;

void findLargest(int **input, int nRows, int mCols)
{
    int i, j, row_sum = INT_MIN, column_sum = INT_MIN, sum, row_index = 0, column_index = 0;
    for (i = 0; i < nRows; i++)
    {
        sum = 0;
        for (j = 0; j < mCols; j++)
        {
            sum += input[i][j];
        }
        if (sum > row_sum)
        {
            row_sum = sum;
            row_index = i;
        }
    }
    for (j = 0; j < mCols; j++)
    {
        sum = 0;
        for (i = 0; i < nRows; i++)
        {
            sum += input[i][j];
        }
        if (sum > column_sum)
        {
            column_sum = sum;
            column_index = j;
        }
    }

    if (row_sum >= column_sum)
    {
        cout << "row " << row_index << " " << row_sum << endl;
    }
    else
    {
        cout << "column " << column_index << " " << column_sum << endl;
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

        int **input = new int *[row];
        for (int i = 0; i < row; i++)
        {
            input[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> input[i][j];
            }
        }

        findLargest(input, row, col);
        cout << endl;
    }
}