#include <iostream>
using namespace std;

int main()
{
    int n, i = 1, j;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= n)
        {
            cout << n - j + 1;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}