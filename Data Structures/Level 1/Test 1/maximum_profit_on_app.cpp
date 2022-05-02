#include <iostream>
#include <algorithm>
using namespace std;

int maximumProfit(int budget[], int n)
{
    sort(budget, budget + n);
    for (int i = 0; i < n; i++)
    {
        budget[i] *= (n - i);
    }
    int max = budget[0];
    for (int i = 1; i < n; i++)
    {
        if (max < budget[i])
        {
            max = budget[i];
        }
    }
    return max;
}

int main()
{
    int n, *input, i, *cost;
    cin >> n;
    input = new int[n];
    for (i = 0; i < n; i++)
        cin >> input[i];

    cout << maximumProfit(input, n) << endl;
}