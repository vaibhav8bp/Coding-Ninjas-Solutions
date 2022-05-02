#include <iostream>
using namespace std;

int main()
{
    int i = 1, n = 3, j, k = 1;
    // cin>>n;
    while (i <= n)
    {
        j = 1;
        while (j <= n - i)
        {
            cout << "  ";
            j++;
        }
        j = 1;
        while (j <= (2 * i) - 1)
        {
            cout << k++ << " ";
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}