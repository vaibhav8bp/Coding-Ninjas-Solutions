#include <iostream>
using namespace std;
int main()
{
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << " ";
            j++;
        }
        j = 1;
        while (j <= (2 * i) - 1)
        {
            cout << j;
            j++;
        }
        cout << endl;
        i++;
    }
    n = n - 1;
    i = n;
    while (i >= 1)
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
            cout << j;
            j++;
        }
        cout << endl;
        i--;
    }
    return 0;
}