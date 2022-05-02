#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(bool *visited, int *distance, int n)
{
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > distance[i] && !visited[i])
        {
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra_algorithm(int **edges, int n)
{
    bool *visited = new bool[n];
    int *distance = new int[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[0] = 0;

    for (int i = 0; i < n - 1; i++)
    {
        int current = findMinVertex(visited, distance, n);
        visited[current] = true;
        for (int j = 0; j < n; j++)
        {
            if (edges[current][j] > 0 && !visited[j])
            {
                int distance_to_reach = distance[current] + edges[current][j];
                int distance_earlier = distance[j];
                if (distance_to_reach < distance_earlier)
                {
                    distance[j] = distance_to_reach;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << i << " " << distance[i] << endl;
    }

    delete[] visited;
    delete[] distance;
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

    dijkstra_algorithm(edges, n);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;

    return 0;
}