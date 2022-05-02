#include <iostream>
using namespace std;

int main()
{
    int i = 0, n, pascal, j;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << " ";
            j++;
        }
        j = 0;
        while (j <= i)
        {
            if (j == 0 || j == i)
            {
                pascal = 1;
            }
            else
            {
                pascal = (pascal * (i - j + 1)) / j;
            }
            cout << pascal << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}