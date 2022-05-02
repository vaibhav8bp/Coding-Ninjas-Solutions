#include <iostream>
using namespace std;

int main()
{
    int i = 1, n, j, a = 1;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        while (j <= i)
        {
            cout << a++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}