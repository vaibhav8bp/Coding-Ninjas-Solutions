#include <iostream>
#include <climits>
using namespace std;

int countMinStepsToOne(int n)
{
    int *ans = new int[n + 1];
    ans[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int a = ans[i - 1];
        int b = INT_MAX;
        int c = INT_MAX;
        if (i % 2 == 0)
        {
            b = ans[i / 2];
        }
        if (i % 3 == 0)
        {
            c = ans[i / 3];
        }
        ans[i] = 1 + min(a, min(b, c));
    }
    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << countMinStepsToOne(n);
}