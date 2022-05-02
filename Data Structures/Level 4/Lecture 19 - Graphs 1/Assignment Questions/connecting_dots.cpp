#include <iostream>
#include <vector>
using namespace std;

int shifter[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool validPosition(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

bool hasCycleHelper(vector<vector<char>> &board, int n, int m, int i, int j, int fromX, int fromY, bool **visited)
{
    visited[i][j] = true;
    bool answer = false;
    for (int x = 0; x < 4; x++)
    {
        int newX = i + shifter[x][0];
        int newY = j + shifter[x][1];
        if (!validPosition(newX, newY, n, m) || (newX == fromX && newY == fromY) || board[i][j] != board[newX][newY])
        {
            continue;
        }
        if (visited[newX][newY])
        {
            return true;
        }
        answer = answer || hasCycleHelper(board, n, m, newX, newY, i, j, visited);
    }
    return answer;
}

bool hasCycle(vector<vector<char>> &board, int n, int m)
{
    bool **visited = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new bool[m];
        for (int j = 0; j < m; j++)
        {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j])
            {
                bool answer = hasCycleHelper(board, n, m, i, j, -1, -1, visited);
                if (answer)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> board[i][j];
        }
    }

    cout << (hasCycle(board, n, m) ? "true" : "false");
}