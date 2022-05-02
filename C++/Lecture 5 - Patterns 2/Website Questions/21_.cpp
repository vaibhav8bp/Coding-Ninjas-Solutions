#include <iostream>
using namespace std;

int main()
{
    int i = 1, j, n, value;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= i)
        {
            if (j == 1)
            {
                value = i;
            }
            else
            {
                value = value + n - j + 1;
            }
            cout << value << " ";
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}