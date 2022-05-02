#include <iostream>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int destination;
    int weight;

    void setValues(int s, int d, int w)
    {
        source = s;
        destination = d;
        weight = w;
    }
};

bool compare(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

void kruskals_algorithm(Edge *input, int n, int e)
{
    sort(input, input + e, compare);
    Edge *output = new Edge[n - 1];
    int count = 0;
    int current = 0;
    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    while (count != n - 1)
    {
        Edge currentEdge = input[current];
        int v1 = currentEdge.source;
        int v2 = currentEdge.destination;
        while (v1 != parent[v1])
        {
            v1 = parent[v1];
        }
        while (v2 != parent[v2])
        {
            v2 = parent[v2];
        }
        if (v1 != v2)
        {
            output[count++] = currentEdge;
            parent[v1] = v2;
        }
        current++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];
    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;
        int tempS = s;
        s = min(s, d);
        d = max(tempS, d);
        Edge x;
        x.setValues(s, d, w);
        input[i] = x;
    }
    kruskals_algorithm(input, n, e);
}