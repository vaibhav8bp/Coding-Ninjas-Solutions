#include <iostream>
#include <cmath>
using namespace std;

int getAllWaysHelper(int a, int b, int start)
{
    if (a == 0)
    {
        return 1;
    }
    int answer = 0;
    for (int i = start; a - pow(i, b) >= 0; i++)
    {
        answer += getAllWaysHelper(a - pow(i, b), b, i + 1);
    }
    return answer;
}

int getAllWays(int a, int b)
{
    return getAllWaysHelper(a, b, 1);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << getAllWays(a, b);
}