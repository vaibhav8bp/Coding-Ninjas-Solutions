#include <iostream>
#include <vector>
using namespace std;

int shifter[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool validPosition(int i, int j, int n)
{
    if (i < 0 || i >= n || j < 0 || j >= n)
    {
        return false;
    }
    return true;
}

int getBiggestPieceSizeHelper(vector<vector<int>> &cake, int n, bool **visited, int i, int j)
{
    visited[i][j] = true;
    int answer = 1;
    for (int x = 0; x < 4; x++)
    {
        int newX = i + shifter[x][0];
        int newY = j + shifter[x][1];
        if (!validPosition(newX, newY, n) || cake[newX][newY] != 1 || visited[newX][newY])
        {
            continue;
        }
        answer += getBiggestPieceSizeHelper(cake, n, visited, newX, newY);
    }
    return answer;
    visited[i][j] = false;
}

int getBiggestPieceSize(vector<vector<int>> &cake, int n)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
        }
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && cake[i][j] == 1)
            {
                answer = max(answer, getBiggestPieceSizeHelper(cake, n, visited, i, j));
            }
        }
    }
    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> cake(n, vector<int>(n));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> cake[i][j];
        }
    }

    cout << getBiggestPieceSize(cake, n);
}