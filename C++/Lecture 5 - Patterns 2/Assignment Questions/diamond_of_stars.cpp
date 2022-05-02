#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j, k;
    cin >> n;
    // First Half
    while (i <= (n / 2) + 1)
    {
        j = 1;
        while (j <= ((n / 2) + 1 - i))
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= ((2 * i) - 1))
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i++;
    }

    // Second Half
    n /= 2;
    i = n;
    while (i > 0)
    {
        j = 1;
        while (j <= n - i + 1)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= (2 * i) - 1)
        {
            cout << "*";
            j++;
        }
        cout << endl;
        i--;
    }
    return 0;
}