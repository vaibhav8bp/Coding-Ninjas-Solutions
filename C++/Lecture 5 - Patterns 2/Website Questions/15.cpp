#include <iostream>
using namespace std;
int main()
{
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= i)
        {
            if (i % 2 == 0 && j % 2 == 0)
            {
                cout << 1;
            }
            else if (i % 2 == 0 && j % 2 != 0)
            {
                cout << 0;
            }
            else if (i % 2 != 0 && j % 2 == 0)
            {
                cout << 0;
            }
            else if (i % 2 != 0 && j % 2 != 0)
            {
                cout << 1;
            }
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}