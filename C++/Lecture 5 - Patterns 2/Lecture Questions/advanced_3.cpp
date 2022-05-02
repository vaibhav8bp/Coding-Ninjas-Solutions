#include <iostream>
using namespace std;
int main()
{
    int i = 1, j, n, k;
    cin >> n;
    // First Half
    while (i <= n)
    {
        j = 1;
        k = n - i;
        while (j <= i - 1)
        {
            cout << " ";
            j++;
        }
        if (i < n)
        {
            cout << i;
        }
        j = 1;
        while (j <= (2 * k) - 1)
        {
            cout << " ";
            j++;
        }
        cout << i << endl;
        i++;
    }
    // Second Half
    i = 1;
    n = n - 1;
    while (i <= n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << " ";
            j++;
        }
        cout << n - i + 1;
        j = 1;
        while (j <= (2 * i) - 1)
        {
            cout << " ";
            j++;
        }
        cout << n - i + 1 << endl;
        i++;
    }

    return 0;
}