#include <iostream>
#include <queue>
using namespace std;

void printBFS(int **edges, int n, bool *visited, int sv)
{
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    while (!pendingNodes.empty())
    {
        int currentVertex = pendingNodes.front();
        pendingNodes.pop();
        if (!visited[currentVertex])
        {
            cout << currentVertex << " ";
            visited[currentVertex] = true;
            for (int i = 0; i < n; i++)
            {
                if (i == currentVertex)
                {
                    continue;
                }
                if (edges[currentVertex][i] == 1 && !visited[i])
                {
                    pendingNodes.push(i);
                }
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            printBFS(edges, n, visited, i);
        }
    }
}

int main()
{
    int n;
    int e;
    cin >> n >> e;
    if (n == 0)
    {
        return 0;
    }
    
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
    BFS(edges, n);
    return 0;
}