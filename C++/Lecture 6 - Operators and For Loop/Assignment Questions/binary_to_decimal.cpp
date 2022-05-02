#include <iostream>
using namespace std;

int power(int x, int n)
{
    int p = 1;
    if (n == 0)
    {
        return 1;
    }
    while (n != 0)
    {
        p = p * x;
        n--;
    }
    return p;
}

int main()
{
    int a, decimal = 0, j = 0;
    long long int n;
    cin >> n;
    while (n != 0)
    {
        a = n % 10;
        decimal = decimal + a * power(2, j);
        j++;
        n /= 10;
    }
    cout << decimal;
    return 0;
}