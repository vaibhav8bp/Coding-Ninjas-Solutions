#include <iostream>
using namespace std;

int main()
{
    int i = 1, x, j;
    cin >> x;
    while (i <= x)
    {
        j = (3 * i) + 2;
        if (j % 4 == 0)
        {
            x++;
            i++;
            continue;
        }
        cout << j << " ";
        i++;
    }
    return 0;
}