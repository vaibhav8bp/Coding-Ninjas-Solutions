#include <iostream>
#include <string>
using namespace std;

bool findWinnerHelper(int n, int x, int y, int *ans)
{
    if (n <= 0)
    {
        return false;
    }
    int atmost = max(1, max(x, y));
    if (n <= atmost)
    {
        return true;
    }
    if (ans[n] != -1)
    {
        return ans[n];
    }
    bool answer = false;
    if (!findWinnerHelper(n - x, x, y, ans))
    {
        answer = true;
    }
    if (!findWinnerHelper(n - y, x, y, ans))
    {
        answer = true;
    }
    if (!findWinnerHelper(n - 1, x, y, ans))
    {
        answer = true;
    }
    ans[n] = answer;
    return answer;
}

string findWinner(int n, int x, int y)
{
    int *ans = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
    {
        ans[i] = -1;
    }
    bool answer = findWinnerHelper(n, x, y, ans);
    if (answer)
    {
        return "Beerus";
    }
    else
    {
        return "Whis";
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}