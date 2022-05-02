#include <iostream>
#include <string>
using namespace std;

bool findWinnerHelper(int n, int x, int y)
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
    bool answer = false;
    if (!findWinnerHelper(n - x, x, y))
    {
        answer = true;
    }
    if (!findWinnerHelper(n - y, x, y))
    {
        answer = true;
    }
    if (!findWinnerHelper(n - 1, x, y))
    {
        answer = true;
    }
    return answer;
}

string findWinner(int n, int x, int y)
{
    bool answer = findWinnerHelper(n, x, y);
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