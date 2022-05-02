#include <iostream>
using namespace std;
int main()
{
    int i = 1, j, k = 6, l = 13, m = 16;
    while (i <= 5)
    {
        j = 1;
        while (j <= 5)
        {
            if (i == 1)
            {
                cout << j << " ";
            }
            else if (j == 5)
            {
                cout << k << " ";
                k++;
            }
            else if (i == 5)
            {
                cout << l;
                l--;
            }
            else if (j == 1)
            {
                cout << m << "   ";
                m--;
            }
            else
            {
                cout << " ";
            }
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}