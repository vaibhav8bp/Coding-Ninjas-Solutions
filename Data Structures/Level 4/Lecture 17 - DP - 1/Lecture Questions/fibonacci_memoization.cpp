#include <iostream>
using namespace std;

int fibonacci_helper(int *ans, int n)
{
    if (n <= 1)
    {
        return n;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = fibonacci_helper(ans, n - 1);
    int b = fibonacci_helper(ans, n - 2);
    ans[n] = a + b;
    return ans[n];
}

int fibonacci(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return fibonacci_helper(ans, n);
}

int main()
{
    cout << fibonacci(6) << endl;
    return 0;
}