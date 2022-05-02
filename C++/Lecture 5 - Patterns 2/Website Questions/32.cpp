#include <iostream>
using namespace std;

int main()
{
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= i - 1)
        {
            cout << i << "*";
            j++;
        }
        cout << i << endl;
        i++;
    }
    i = 1;
    while (i <= n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << n - i + 1 << "*";
            j++;
        }
        cout << n - i + 1 << endl;
        i++;
    }
    return 0;
}