#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= i)
        {
            if (i % 2 == 0)
            {
                cout << (2 * j) << " ";
            }
            else
            {
                cout << ((2 * j) - 1) << " ";
            }
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}