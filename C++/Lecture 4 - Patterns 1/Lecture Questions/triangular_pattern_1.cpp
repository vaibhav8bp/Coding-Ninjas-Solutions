#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= i)
        {
            cout << j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}