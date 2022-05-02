#include <iostream>
using namespace std;

int main()
{
    int i = 1, j, n, k;
    cin >> n;
    while (i <= n)
    {
        j = n - i + 1;
        k = 1;
        while (k <= n)
        {
            if (j == n)
            {
                cout << n;
            }
            else
            {
                cout << j;
                j++;
            }
            k++;
        }
        cout << endl;
        i++;
    }
    return 0;
}