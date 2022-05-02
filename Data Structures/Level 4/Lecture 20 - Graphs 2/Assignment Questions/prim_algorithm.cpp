#include <iostream>
#include <climits>
using namespace std;

int minimum(bool *visited, int *weight, int n)
{
    int s = INT_MAX;
    int current_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && s > weight[i])
        {
            s = weight[i];
            current_index = i;
        }
    }
    return current_index;
}

void prim_algorithm(int **edges, int n)
{
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
        parent[i] = -1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int current = minimum(visited, weight, n);
        for (int j = 0; j < n; j++)
        {
            if (edges[current][j] > 0 && (weight[j] > edges[current][j]) && !visited[j])
            {
                weight[j] = edges[current][j];
                parent[j] = current;
            }
        }
        visited[current] = true;
    }
    
    for (int i = 1; i < n; i++)
    {
        int p = parent[i];
        cout << min(i, p) << " " << max(i, p) << " " << edges[i][p] << endl;
    }
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
        int s, d, w;
        cin >> s >> d >> w;
        edges[s][d] = w;
        edges[d][s] = w;
    }
    prim_algorithm(edges, n);
}