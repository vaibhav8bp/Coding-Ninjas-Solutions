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
        while (j >= 1)
        {
            cout << j--;
        }
        j = 2;
        while (j <= i)
        {
            cout << j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}