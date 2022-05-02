#include <iostream>
using namespace std;

void top_to_bottom(int **input, int nRows, int j)
{
	int i;
	for (i = 0; i < nRows; i++)
	{
		cout << input[i][j] << " ";
	}
}

void bottom_to_top(int **input, int nRows, int j)
{
	int i;
	for (i = nRows - 1; i >= 0; i--)
	{
		cout << input[i][j] << " ";
	}
}

void wavePrint(int **input, int nRows, int mCols)
{
	int i, j;
	for (j = 0; j < mCols; j++)
	{
		if (j % 2 == 0)
		{
			top_to_bottom(input, nRows, j);
		}
		else
		{
			bottom_to_top(input, nRows, j);
		}
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
		wavePrint(input, row, col);
		cout << endl;
	}
}