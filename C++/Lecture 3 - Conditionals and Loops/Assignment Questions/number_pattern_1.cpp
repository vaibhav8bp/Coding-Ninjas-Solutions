#include <iostream>
using namespace std;

int main()
{
    int n, i = 1, k, a = 1;
    cin >> n;
    while (i <= n)
    {
        k = i;
        a = 1;
        while (a <= i)
        {
            cout << k++;
            a++;
        }
        cout << endl;
        i++;
    }
    return 0;
}