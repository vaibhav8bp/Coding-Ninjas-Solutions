#include <iostream>
using namespace std;

long long int power(int x, int n)
{
    long long int p = 1;
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
    long long int binary = 0;
    int n;
    int j = 0;
    cin >> n;
    while (n != 0)
    {
        binary += (n % 2) * power(10, j);
        j++;
        n /= 2;
    }
    cout << binary << endl;
}