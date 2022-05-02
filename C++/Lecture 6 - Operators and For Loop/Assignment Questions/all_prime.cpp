#include <iostream>
using namespace std;

int main()
{
    int n, i = 2, j;
    cin >> n;
    while (i <= n)
    {
        for (j = 2; j < i; j++)
        {
            if (i % j == 0)
            {
                break;
            }
        }
        if (j == i)
        {
            cout << i << endl;
        }
        i++;
    }
    return 0;
}