#include <iostream>
using namespace std;

int count(int n)
{
    if (n <= 9)
    {
        return 1;
    }
    return count(n / 10) + 1;
}

int main()
{
    int n;
    cin >> n;
    cout << count(n) << endl;
}
