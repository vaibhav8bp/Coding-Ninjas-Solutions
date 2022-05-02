#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> returnAllConnectedComponentsDFSHelper(int **edges, int n, bool *visited, int sv, vector<int> &smallOutput)
{
    visited[sv] = true;
    smallOutput.push_back(sv);
    for (int i = 0; i < n; i++)
    {
        if (edges[sv][i] == 1 && !visited[i])
        {
            returnAllConnectedComponentsDFSHelper(edges, n, visited, i, smallOutput);
        }
    }
    return smallOutput;
}

vector<vector<int>> returnAllConnectedComponentsDFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<vector<int>> answer;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> smallOutput(0);
            smallOutput = returnAllConnectedComponentsDFSHelper(edges, n, visited, i, smallOutput);
            sort(smallOutput.begin(), smallOutput.end());
            answer.push_back(smallOutput);
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
    vector<vector<int>> answer = returnAllConnectedComponentsDFS(edges, n);
    for (int i = 0; i < answer.size(); i++)
    {
        for (int j = 0; j < answer.at(i).size(); j++)
        {
            cout << answer.at(i).at(j) << " ";
        }
        cout << endl;
    }
    return 0;
}