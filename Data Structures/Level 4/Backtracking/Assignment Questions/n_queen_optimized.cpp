#include <bits/stdc++.h>
using namespace std;

void nQueenHelper(int current_row, int n, int **chessBoard, int *up, int *left_diagonal, int *right_diagonal)
{
    if (current_row == n)
    {
        // We have reached some solution
        // Print the board
        // Return
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << chessBoard[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }

    // Place at all possible positions and move to smaller problem
    for (int j = 0; j < n; j++)
    {
        if (up[j] != 1 && right_diagonal[current_row + j] != 1 && left_diagonal[n - 1 + current_row - j] != 1)
        {
            chessBoard[current_row][j] = 1;
            up[j] = 1;
            right_diagonal[current_row + j] = 1;
            left_diagonal[n - 1 + current_row - j] = 1;
            nQueenHelper(current_row + 1, n, chessBoard, up, left_diagonal, right_diagonal);
            chessBoard[current_row][j] = 0;
            up[j] = 0;
            right_diagonal[current_row + j] = 0;
            left_diagonal[n - 1 + current_row - j] = 0;
        }
    }
}

void nQueen(int n)
{
    int **chessBoard = new int *[n];
    for (int i = 0; i < n; i++)
    {
        chessBoard[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            chessBoard[i][j] = 0;
        }
    }
    int *up = new int[n - 1];
    memset(up, 0, n - 1);
    int *left_diagonal = new int[(2 * n) - 1];
    memset(left_diagonal, 0, (2 * n) - 1);
    int *right_diagonal = new int[(2 * n) - 1];
    memset(right_diagonal, 0, (2 * n) - 1);
    nQueenHelper(0, n, chessBoard, up, left_diagonal, right_diagonal);
    for (int i = 0; i < n; i++)
    {
        delete[] chessBoard[i];
    }
    delete[] chessBoard;
    up = nullptr;
    left_diagonal = nullptr;
    right_diagonal = nullptr;
    delete[] up;
    delete[] left_diagonal;
    delete[] right_diagonal;
}

int main()
{
    int n;
    cin >> n;
    nQueen(n);
    return 0;
}