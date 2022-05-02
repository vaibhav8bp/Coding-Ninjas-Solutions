#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int minCount(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int i = 1;
    int j = INT_MAX;
    while (i * i <= n)
    {
        j = min(j, minCount(n - pow(i, 2)));
        i++;
    }
    return j + 1;
}

int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
}