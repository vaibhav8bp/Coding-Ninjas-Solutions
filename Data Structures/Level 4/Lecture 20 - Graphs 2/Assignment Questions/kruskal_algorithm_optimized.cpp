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

int findParent(int v, int *parent)
{
    if (v == parent[v])
    {
        return v;
    }
    parent[v] = findParent(parent[v], parent);
    return parent[v];
}

void kruskals_algorithm(Edge *input, int n, int e)
{
    sort(input, input + e, compare);
    Edge *output = new Edge[n - 1];
    int count = 0;
    int current = 0;
    int *parent = new int[n];
    int *rank = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
    while (count != n - 1)
    {
        Edge currentEdge = input[current];
        int v1 = currentEdge.source;
        int v2 = currentEdge.destination;
        v1 = findParent(v1, parent);
        v2 = findParent(v2, parent);
        if (v1 != v2)
        {
            output[count++] = currentEdge;
            if (rank[v1] == rank[v2])
            {
                parent[v1] = v2;
                rank[v2]++;
            }
            else if (rank[v1] < rank[v2])
            {
                parent[v1] = v2;
            }
            else
            {
                parent[v2] = v1;
            }
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