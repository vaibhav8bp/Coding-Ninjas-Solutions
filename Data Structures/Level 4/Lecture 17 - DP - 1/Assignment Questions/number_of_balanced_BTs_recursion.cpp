#include <iostream>
using namespace std;

long long int balancedBTs(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    long long int x = balancedBTs(n - 1);
    long long int y = balancedBTs(n - 2);
    long long int mod = 1e9 + 7;
    long long int temp1 = (x * x) % mod;
    long long int temp2 = (2 * x * y) % mod;
    return (temp1 + temp2) % mod;
}

int main()
{
    int n;
    cin >> n;
    cout << balancedBTs(n);
}