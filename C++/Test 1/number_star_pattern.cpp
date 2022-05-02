#include <iostream>
using namespace std;

int main()
{
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        // First Half
        while (j <= n)
        {
            if (j <= n - i + 1)
            {
                cout << j++;
            }
            else
            {
                cout << "*";
                j++;
            }
        }
        // Second Half
        j = n;
        while (j >= 1)
        {
            if (j <= n - i + 1)
            {
                cout << j--;
            }
            else
            {
                cout << "*";
                j--;
            }
        }
        cout << endl;
        i++;
    }
    return 0;
}