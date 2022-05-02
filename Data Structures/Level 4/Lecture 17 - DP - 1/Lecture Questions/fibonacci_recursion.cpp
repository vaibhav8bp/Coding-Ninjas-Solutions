#include <iostream>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int a = fibonacci(n - 1);
    int b = fibonacci(n - 2);
    return a + b;
}

int main()
{
    cout << fibonacci(6) << endl;
    return 0;
}