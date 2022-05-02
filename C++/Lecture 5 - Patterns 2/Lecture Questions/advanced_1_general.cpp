#include <iostream>
using namespace std;
int main()
{
    int i = 1, j, k, l, n, m;
    cin >> n;
    k = n + 1;                         //7
    l = (3 * n) - 2;                   //16
    m = (n * n) - ((n - 2) * (n - 2)); //20
    while (i <= n)
    {
        j = 1;
        while (j <= n)
        {
            if (i == 1)
            {
                cout << j << "  ";
            }
            else if (j == n)
            {
                cout << k++ << " ";
            }
            else if (i == n)
            {
                cout << l-- << " ";
            }
            else if (j == 1)
            {
                cout << m-- << "        ";
            }
            else
            {
                cout << " ";
            }
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}