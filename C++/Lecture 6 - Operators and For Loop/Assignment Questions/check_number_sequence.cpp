#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int previous = INT_MAX;
    int A = INT_MIN;
    int i = 1, n, current;
    cin >> n;
    while (i <= n)
    {
        cin >> current;
        if (A > current || previous == current)
        {
            cout << "false" << endl;
            break;
        }
        if (previous > current)
        {
            previous = current;
        }
        else if (previous < current)
        {
            previous = current;
            A = current;
        }
        i++;
    }
    if (i == n + 1)
    {
        cout << "true" << endl;
    }
    return 0;
}