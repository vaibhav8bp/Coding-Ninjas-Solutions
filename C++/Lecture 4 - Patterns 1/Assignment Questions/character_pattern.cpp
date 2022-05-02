#include <iostream>
using namespace std;

int main()
{
    char c;
    int i = 1, n, j, k;
    cin >> n;
    while (i <= n)
    {
        c = 'A' + i - 1;
        j = 1;
        while (j <= i)
        {
            cout << c++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}