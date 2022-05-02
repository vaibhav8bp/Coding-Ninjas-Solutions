#include <iostream>
#include <climits>
using namespace std;

int countMinStepsToOneHelper(int *ans, int n)
{
    if (n == 1)
    {
        return 0;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    int a = countMinStepsToOneHelper(ans, n - 1);
    int b = INT_MAX, c = INT_MAX;
    if (n % 2 == 0)
    {
        b = countMinStepsToOneHelper(ans, n / 2);
    }
    if (n % 3 == 0)
    {
        c = countMinStepsToOneHelper(ans, n / 3);
    }
    ans[n] = 1 + min(a, min(b, c));
    return ans[n];
}

int countMinStepsToOne(int n)
{
    int *ans = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        ans[i] = -1;
    }
    return countMinStepsToOneHelper(ans, n);
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}