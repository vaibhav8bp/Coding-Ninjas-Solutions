#include <iostream>
using namespace std;

int main()
{
    int i = 1, j, n, k;
    cin >> n;
    cout << "0\n";
    while (i <= n)
    {
        j = 1;
        k = n - i + 1;
        while (j <= i)
        {
            cout << k;
            k++;
            j++;
        }
        cout << "0";
        j = 1;
        k = n;
        while (j <= i)
        {
            cout << k;
            k--;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}