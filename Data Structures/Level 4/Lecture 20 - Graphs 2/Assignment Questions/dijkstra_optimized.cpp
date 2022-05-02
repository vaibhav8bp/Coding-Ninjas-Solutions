#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

void dijkstra_optimized(vector<pair<int, int>> graph[], int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});
    for (int i = 0; i < n - 1; i++)
    {
        int current = pq.top().second;
        pq.pop();
        visited[current] = true;
        for (int j = 0; j < graph[current].size(); j++)
        {
            if (!visited[graph[current].at(j).first])
            {
                int distance_to_reach = distance[current] + graph[current].at(j).second;
                int distance_earlier = distance[graph[current].at(j).first];
                if (distance_to_reach < distance_earlier)
                {
                    distance[graph[current].at(j).first] = distance_to_reach;
                    pq.push({distance[graph[current].at(j).first], graph[current].at(j).first});
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
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
        p.first = s;
        p.second = w;
        graph[d].push_back(p);
        q.first = d;
        q.second = w;
        graph[s].push_back(q);
    }
    dijkstra_optimized(graph, n);
    return 0;
}