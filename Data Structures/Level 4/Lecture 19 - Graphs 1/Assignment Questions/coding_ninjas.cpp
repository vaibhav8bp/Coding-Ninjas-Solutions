#include <iostream>
#include <vector>
using namespace std;

string value = "CODINGNINJA";
int shifter[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool validIndex(int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
    {
        return false;
    }
    return true;
}

bool hasPathHelper(vector<vector<char>> &board, int n, int m, int i, int j, int current_index, bool **visited)
{
    if (value[current_index] == '\0')
    {
        return true;
    }
    visited[i][j] = true;
    bool answer = false;
    for (int x = 0; x < 8; x++)
    {
        int newX = i + shifter[x][0];
        int newY = j + shifter[x][1];
        if (validIndex(newX, newY, n, m) && !visited[newX][newY] && board[newX][newY] == value[current_index])
        {
            answer = answer || hasPathHelper(board, n, m, newX, newY, current_index + 1, visited);
        }
    }
    visited[i][j] = false;
    return answer;
}

bool hasPath(vector<vector<char>> &board, int n, int m)
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
            if (board.at(i).at(j) == 'C')
            {
                bool answer = hasPathHelper(board, n, m, i, j, 1, visited);
                if (answer)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

// #include <iostream>
// #include <vector>
// #include <cstring>
// using namespace std;

// string value = "CODINGNINJA";

// bool hasPathHelper(vector<vector<char>> &board, int n, int m, int i, int j, int current_index, bool **visited)
// {
//     if (value[current_index] == '\0')
//     {
//         return true;
//     }
//     if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] != value[current_index] || visited[i][j])
//     {
//         return false;
//     }

//     visited[i][j] = true;

//     bool a = hasPathHelper(board, n, m, i - 1, j - 1, current_index + 1, visited);
//     bool b = hasPathHelper(board, n, m, i - 1, j, current_index + 1, visited);
//     bool c = hasPathHelper(board, n, m, i - 1, j + 1, current_index + 1, visited);
//     bool d = hasPathHelper(board, n, m, i, j - 1, current_index + 1, visited);
//     bool e = hasPathHelper(board, n, m, i, j + 1, current_index + 1, visited);
//     bool f = hasPathHelper(board, n, m, i + 1, j - 1, current_index + 1, visited);
//     bool g = hasPathHelper(board, n, m, i + 1, j, current_index + 1, visited);
//     bool h = hasPathHelper(board, n, m, i + 1, j + 1, current_index + 1, visited);

//     visited[i][j] = false;

//     return a || b || c || d || e || f || g || h;

// }

// bool hasPath(vector<vector<char>> &board, int n, int m)
// {
//     bool **visited = new bool *[n];
//     for (int i = 0; i < n; i++)
//     {
//         visited[i] = new bool[m];
//         for (int j = 0; j < m; j++)
//         {
//             visited[i][j] = false;
//         }
//     }
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             if (board.at(i).at(j) == 'C')
//             {
//                 bool answer = hasPathHelper(board, n, m, i, j, 0, visited);
//                 if (answer)
//                 {
//                     return true;
//                 }
//             }
//         }
//     }
//     return false;
// }