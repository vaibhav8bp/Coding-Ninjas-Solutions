#include <iostream>
using namespace std;

bool isPossible(int current_row, int current_column, int n, int **chessBoard)
{
    // Same column
    for (int i = current_row - 1; i >= 0; i--)
    {
        if (chessBoard[i][current_column] == 1)
        {
            return false;
        }
    }

    // Upper left diagonal
    for (int i = current_row - 1, j = current_column - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (chessBoard[i][j] == 1)
        {
            return false;
        }
    }
    // Upper right diagonal
    for (int i = current_row - 1, j = current_column + 1; i >= 0 && j < n; i--, j++)
    {
        if (chessBoard[i][j] == 1)
        {
            return false;
        }
    }
    return true;
}

void nQueenHelper(int current_row, int n, int **chessBoard)
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
        if (isPossible(current_row, j, n, chessBoard))
        {
            chessBoard[current_row][j] = 1;
            nQueenHelper(current_row + 1, n, chessBoard);
            chessBoard[current_row][j] = 0;
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
    nQueenHelper(0, n, chessBoard);
    for (int i = 0; i < n; i++)
    {
        delete[] chessBoard[i];
    }
    delete[] chessBoard;
}

int main()
{
    int n;
    cin >> n;
    nQueen(n);
    return 0;
}