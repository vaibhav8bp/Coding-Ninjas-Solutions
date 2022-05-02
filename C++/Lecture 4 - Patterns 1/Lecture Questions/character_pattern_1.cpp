#include <iostream>
using namespace std;

int main()
{
    char c = 65;
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = 1;
        c = 65;
        while (j <= n)
        {
            cout << c;
            c++;
            j++;
        }
        cout << endl;
        i++;
    }
    return 0;
}