#include <iostream>
using namespace std;

void rat_in_a_maze_helper(int current_row, int current_column, int n, int **maze, int **visited)
{
    if (current_row == n - 1 && current_column == n - 1)
    {
        visited[current_row][current_column] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << visited[i][j] << " ";
            }
        }
        cout << endl;
        visited[current_row][current_column] = 0;
        return;
    }
    if (current_row < 0 || current_row >= n || current_column < 0 || current_column >= n || visited[current_row][current_column] == 1 || maze[current_row][current_column] == 0)
    {
        return;
    }
    visited[current_row][current_column] = 1;
    rat_in_a_maze_helper(current_row - 1, current_column, n, maze, visited);
    rat_in_a_maze_helper(current_row + 1, current_column, n, maze, visited);
    rat_in_a_maze_helper(current_row, current_column - 1, n, maze, visited);
    rat_in_a_maze_helper(current_row, current_column + 1, n, maze, visited);
    visited[current_row][current_column] = 0;
}

void rat_in_a_maze(int n, int **maze)
{
    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }

    rat_in_a_maze_helper(0, 0, n, maze, visited);

    for (int i = 0; i < n; i++)
    {
        delete[] visited[i];
    }
    delete[] visited;
}

int main()
{
    int n;
    cin >> n;
    int **maze = new int *[n];
    for (int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    rat_in_a_maze(n, maze);
    for (int i = 0; i < n; i++)
    {
        delete[] maze[i];
    }
    delete[] maze;
    return 0;
}