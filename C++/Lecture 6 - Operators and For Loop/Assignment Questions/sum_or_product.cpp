#include <iostream>
using namespace std;

int main()
{
    int n, choice;
    cin >> n;
    cin >> choice;
    if (choice == 1)
    {
        int i = 1, sum = 0;
        while (i <= n)
        {
            sum += i;
            i++;
        }
        cout << sum << endl;
    }
    else if (choice == 2)
    {
        int i = 1, product = 1;
        while (i <= n)
        {
            product *= i;
            i++;
        }
        cout << product << endl;
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}