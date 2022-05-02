#include <iostream>
using namespace std;

// 0 1 1 2 3 5 8 13 21 34 55
// 0 1 2 3 4 5 6  7  8  9 10
int fibonacci(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    cout << fibonacci(10);
    return 0;
}