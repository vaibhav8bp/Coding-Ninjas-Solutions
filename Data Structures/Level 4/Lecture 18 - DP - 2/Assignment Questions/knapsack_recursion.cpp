#include <iostream>
#include <climits>
using namespace std;

int knapsack_helper(int *weights, int *values, int n, int maxWeight, int final)
{
    if (n == 0 || maxWeight == 0)
    {
        return final;
    }
    int a = INT_MIN;
    if (maxWeight - weights[0] >= 0)
    {
        a = knapsack_helper(weights + 1, values + 1, n - 1, maxWeight - weights[0], final + values[0]);
    }

    int b = knapsack_helper(weights + 1, values + 1, n - 1, maxWeight, final);
    return max(a, b);
}

int knapsack(int *weights, int *values, int n, int maxWeight)
{
    return knapsack_helper(weights, values, n, maxWeight, 0);
}

int main()
{
    int n;
    cin >> n;

    int *weights = new int[n];
    int *values = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
    }

    int maxWeight;
    cin >> maxWeight;

    cout << knapsack(weights, values, n, maxWeight) << endl;

    delete[] weights;
    delete[] values;
}