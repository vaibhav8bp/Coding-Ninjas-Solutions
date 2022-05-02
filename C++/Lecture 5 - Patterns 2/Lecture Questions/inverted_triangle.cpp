#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j;
    cin >> n;
    i = 1;
    while (i <= n)
    {
        j = 1;
        while (j <= n - i + 1)
        {
            cout << "*";
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}