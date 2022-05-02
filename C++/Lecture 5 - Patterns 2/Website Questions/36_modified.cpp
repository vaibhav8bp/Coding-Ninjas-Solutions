#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j, k;
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
        k = i;
        while (j <= i)
        {
            cout << k--;
            j++;
        }
        j = 1;
        k = 2;
        while (j <= i - 1)
        {
            cout << k++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}
