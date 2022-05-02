#include <iostream>
using namespace std;
int main()
{
    int sum_even = 0, sum_odd = 0, n;
    cin >> n;
    while (n != 0)
    {
        int a = n % 10;
        if (a % 2 == 0)
        {
            sum_even += a;
        }
        else
        {
            sum_odd += a;
        }
        n = n / 10;
    }
    cout << sum_even << " " << sum_odd << endl;
    return 0;
}