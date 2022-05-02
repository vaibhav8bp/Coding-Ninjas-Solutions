#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j, k = 1;
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
        while (j <= i)
        {
            cout << k;
            k++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}