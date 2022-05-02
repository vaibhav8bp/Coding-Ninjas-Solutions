#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, i = 1, max = INT_MIN, input, s_max = INT_MIN, count = 0;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> input;
        if (input > max)
        {
            s_max = max;
            max = input;
        }
        else if (input > s_max && input < max)
        {
            s_max = input;
        }
    }
    cout << s_max;
    return 0;
}