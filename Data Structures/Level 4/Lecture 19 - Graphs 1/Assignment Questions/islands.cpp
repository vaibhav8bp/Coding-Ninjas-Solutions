#include <iostream>
using namespace std;

void islandsHelper(int **edges, int n, bool *visited, int sv)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            islandsHelper(edges, n, visited, i);
        }
    }
}

int islands(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            islandsHelper(edges, n, visited, i);
            answer++;
        }
    }
    return answer;
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
    int answer = islands(edges, n);
    cout << answer << endl;
    return 0;
}