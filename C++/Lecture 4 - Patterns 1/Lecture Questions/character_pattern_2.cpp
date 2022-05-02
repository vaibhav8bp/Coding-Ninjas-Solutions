#include <iostream>
using namespace std;
int main()
{
    char c;
    int i = 1, n, k;
    cin >> n;
    while (i <= n)
    {
        c = 'A' + i - 1;
        k = 1;
        while (k <= n)
        {
            cout << c++;
            k++;
        }
        cout << endl;
        i++;
    }
    return 0;
}