#include <iostream>
using namespace std;

void isConnectedDFSHelper(int **edges, int n, bool *visited, int sv)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            isConnectedDFSHelper(edges, n, visited, i);
        }
    }
}

bool isConnectedDFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    isConnectedDFSHelper(edges, n, visited, 0);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
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
    if (isConnectedDFS(edges, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}