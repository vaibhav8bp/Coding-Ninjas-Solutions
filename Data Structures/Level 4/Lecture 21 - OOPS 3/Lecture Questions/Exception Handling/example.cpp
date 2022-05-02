#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    try
    {
        cout << "Enter two no's : ";
        cin >> n1 >> n2;
        if (n2 == 0)
        {
            throw "Divide by zero";
        }
        else
        {
            throw n1 / n2;
        }
    }
    catch (char const *s)
    {
        cout << s;
    }
    catch (int ans)
    {
        cout << ans;
    }
    cout << endl
         << "Done" << endl;
}