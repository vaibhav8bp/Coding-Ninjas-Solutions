#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

void prim_optimized(vector<pair<int, int>> graph[], int n)
{
    bool *visited = new bool[n];
    int *weight = new int[n];
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        weight[i] = INT_MAX;
    }
    weight[0] = 0;
    parent[0] = -1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});

    while (!pq.empty())
    {
        // current specifies the index
        //.second()->current-neighbour weight
        //.first()-> neighbour index
        int current = pq.top().second;
        pq.pop();
        visited[current] = true;
        for (int i = 0; i < graph[current].size(); i++)
        {
            int index = graph[current].at(i).first;
            int edge_weight = graph[current].at(i).second;
            if ((edge_weight < weight[index]) && !visited[index])
            {
                weight[index] = edge_weight;
                parent[index] = current;
                pq.push({weight[index], index});
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        int p = parent[i];
        cout << min(i, p) << " " << max(i, p) << " " << weight[i] << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    vector<pair<int, int>> graph[n];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        pair<int, int> p, q;
        p.first = d;
        p.second = w;
        q.first = s;
        q.second = w;
        graph[s].push_back(p);
        graph[d].push_back(q);
    }
    prim_optimized(graph, n);
    return 0;
}

/*

GFG example

5 7
0 1 2
0 3 6
2 1 3
1 3 8
1 4 5
4 2 7
4 3 9

*/