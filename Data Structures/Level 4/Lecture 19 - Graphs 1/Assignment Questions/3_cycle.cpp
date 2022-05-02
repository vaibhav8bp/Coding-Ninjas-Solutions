#include <bits/stdc++.h>
using namespace std;

void DFS(int **edges, bool visited[], int n, int k, int current, int start, int &count)
{
    visited[current] = true;
    if (k == 0)
    {
        visited[current] = false;
        if (edges[current][start] == 1)
        {
            count++;
        }
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && edges[current][i] == 1)
        {
            DFS(edges, visited, n, k - 1, i, start, count);
        }
    }

    visited[current] = false;
}

int countCycles(int **edges, int n, int k)
{
    // all vertex are marked un-visited initially.
    bool visited[n];
    memset(visited, 0, sizeof(visited));

    // Searching for cycle by using v-n+1 vertices
    int count = 0;
    for (int i = 0; i < n - (k - 1); i++)
    {
        DFS(edges, visited, n, k - 1, i, i, count);
        // ith vertex is marked as visited and
        // will not be visited again.
        visited[i] = true;
    }
    return count / 2;
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
        edges[s][f] = edges[f][s] = 1;
    }
    int k = 3;
    cout << countCycles(edges, n, k);
    return 0;
}