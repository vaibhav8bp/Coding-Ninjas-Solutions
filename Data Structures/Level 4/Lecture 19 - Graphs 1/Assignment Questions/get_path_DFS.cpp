#include <iostream>
#include <vector>
using namespace std;

vector<int> getPathDFSHelper(int **edges, int n, bool *visited, int sv, int v2)
{
    if (sv == v2)
    {
        vector<int> answer;
        answer.push_back(sv);
        return answer;
    }
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            vector<int> answer = getPathDFSHelper(edges, n, visited, i, v2);
            if (!answer.empty())
            {
                answer.push_back(sv);
                return answer;
            }
        }
    }
    return vector<int>(0);
}

vector<int> getPathDFS(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    return getPathDFSHelper(edges, n, visited, v1, v2);
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

    vector<int> answer = getPathDFS(edges, n, v1, v2);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << " ";
    }
    return 0;
}