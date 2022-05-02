#include <iostream>
using namespace std;

int main()
{
    int n, i = 1, k, j = 1;
    cin >> n;
    while (i <= n)
    {
        j = i;
        k = 1;
        while (k <= n - i)
        {
            cout << " ";
            k++;
        }
        k = 1;
        while (k <= i)
        {
            cout << j;
            j++;
            k++;
        }
        cout << endl;
        i++;
    }
    return 0;
}