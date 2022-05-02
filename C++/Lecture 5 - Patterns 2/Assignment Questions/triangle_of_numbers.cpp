#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << " ";
            j++;
        }
        j = i;
        while (j <= ((2 * i) - 1))
        {
            cout << j;
            j++;
        }
        j -= 2;
        while (j >= i)
        {
            cout << j;
            j--;
        }
        i++;
        cout << endl;
    }
    return 0;
}