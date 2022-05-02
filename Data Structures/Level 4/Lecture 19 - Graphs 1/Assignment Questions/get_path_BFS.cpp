#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> getPathBFS(int **edges, int n, int v1, int v2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> pendingNodes;
    pendingNodes.push(v1);
    visited[v1] = true;
    unordered_map<int, int> mapping;
    while (!pendingNodes.empty())
    {
        int currentVertex = pendingNodes.front();
        if (currentVertex == v2)
        {
            break;
        }
        pendingNodes.pop();
        for (int i = 0; i < n; i++)
        {
            if (edges[currentVertex][i] == 1 && !visited[i])
            {
                pendingNodes.push(i);
                mapping[i] = currentVertex;
                visited[i] = true;
            }
        }
    }
    if (pendingNodes.empty())
    {
        return vector<int>(0);
    }
    vector<int> answer;
    answer.push_back(v2);
    while (v2 != v1)
    {
        answer.push_back(mapping[v2]);
        v2 = mapping[v2];
    }
    return answer;
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
    vector<int> answer = getPathBFS(edges, n, v1, v2);

    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer.at(i) << " ";
    }

    return 0;
}