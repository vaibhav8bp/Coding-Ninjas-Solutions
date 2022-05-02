#include <iostream>
using namespace std;

int main()
{
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = i;
        while (j > 0)
        {
            cout << j--;
        }
        cout << endl;
        i++;
    }
    return 0;
}