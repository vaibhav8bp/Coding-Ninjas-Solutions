#include <iostream>
using namespace std;

int power(int base, int exponent)
{
    int p = 1;
    if (base == 0 && exponent == 0)
    {
        return 1;
    }
    else
    {
        while (exponent != 0)
        {
            p = base * p;
            exponent -= 1;
        }
        return p;
    }
}

int main()
{
    int base, exponent;
    cin >> base >> exponent;
    cout << power(base, exponent);
    return 0;
}