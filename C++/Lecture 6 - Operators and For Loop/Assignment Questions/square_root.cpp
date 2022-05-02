#include <iostream>
using namespace std;

int square_root(int n)
{
    int i = 1, sq;
    while (i <= n)
    {
        if (n % (i * i) < n)
        {
            sq = i;
        }
        else
        {
            break;
        }
        i++;
    }
    return sq;
}
int main()
{
    int n;
    cin >> n;
    cout << square_root(n) << endl;
    return 0;
}