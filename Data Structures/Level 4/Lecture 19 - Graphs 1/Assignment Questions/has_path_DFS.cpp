#include <iostream>
using namespace std;

bool checkPathDFSHelper(int **edges, int n, bool *visited, int sv, int v2)
{
    if (edges[sv][v2] == 1)
    {
        return true;
    }
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            if (checkPathDFSHelper(edges, n, visited, i, v2))
            {
                return true;
            }
        }
    }
    return false;
}

bool checkPathDFS(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return checkPathDFSHelper(edges, n, visited, v1, v2);
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        // Initially no edges
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    int v1, v2;
    cin >> v1 >> v2;
    if (checkPathDFS(edges, n, v1, v2))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}