#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int n1 = (n + 1) / 2;
    int n2 = n / 2;
    int i = 1, j;
    while (i <= n1)
    {
        j = 1;
        while (j <= n1 - i)
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
        i++;
    }
    i = n2;
    int r = 1;
    while (i>=0)
    {
        j = 1;
        while (j <= r)
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
        r++;
    }
    return 0;
}