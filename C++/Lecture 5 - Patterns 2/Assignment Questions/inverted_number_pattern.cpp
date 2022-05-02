#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j;
    cin >> n;
    i = 1;
    while (i <= n)
    {
        j = n - i + 1;
        while (j >= 1)
        {
            cout << n - i + 1;
            j--;
        }
        i++;
        cout << endl;
    }
    return 0;
}