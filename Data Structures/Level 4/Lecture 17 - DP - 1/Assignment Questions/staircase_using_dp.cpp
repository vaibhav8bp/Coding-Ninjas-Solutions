#include <iostream>
using namespace std;

long staircase(int n)
{
    long *ans = new long[n + 1];
    ans[0] = 1;
    if (n >= 1)
    {
        ans[1] = 1;
    }
    if (n >= 2)
    {
        ans[2] = 2;
    }
    for (long i = 3; i <= n; i++)
    {
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << staircase(n);
}