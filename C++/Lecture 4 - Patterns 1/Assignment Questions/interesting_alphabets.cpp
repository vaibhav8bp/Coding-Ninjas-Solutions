#include <iostream>
using namespace std;

int main()
{
    char c;
    int i = 1, n, j;
    cin >> n;
    while (i <= n)
    {
        c = 'A' + n - i;
        j = 1;
        while (j <= i)
        {
            cout << c++;
            j++;
        }
        i++;
        cout << endl;
    }
    return 0;
}