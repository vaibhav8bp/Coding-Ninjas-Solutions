#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    int i = 2;
    while (i <= a / 2)
    {
        if (a % i == 0)
        {
            cout << "Non-Prime" << endl;
            break;
        }
        else
        {
            i++;
        }
    }
    if (i == ((a / 2) + 1))
    {
        cout << "Prime";
    }
    return 0;
}