#include <iostream>
using namespace std;

int main()
{
    char c;
    int i = 1, j, n;
    cin >> n;
    while (i <= n)
    {
        j = n - i + 1;
        c = 65;
        while (j >= 1)
        {
            cout << c;
            c++;
            j--;
        }
        cout << endl;
        i++;
    }
    return 0;
}