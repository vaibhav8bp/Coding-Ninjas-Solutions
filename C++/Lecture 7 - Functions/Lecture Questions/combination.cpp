#include <iostream>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    if (n == 0)
    {
        return 1;
    }
    while (n >= 1)
    {
        fact *= n;
        n--;
    }
    return fact;
}
int main()
{
    int n, r;
    cin >> n >> r;
    if (n < r)
    {
        cout << "Invalid" << endl;
    }
    else
    {
        cout << factorial(n) / (factorial(n - r) * factorial(r));
    }
    return 0;
}