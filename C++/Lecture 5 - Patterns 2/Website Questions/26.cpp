#include <iostream>
using namespace std;

int main()
{
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= n)
        {
            if (j == n - i + 1)
            {
                cout << "*";
            }
            else
            {
                cout << n - j + 1;
            }
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}