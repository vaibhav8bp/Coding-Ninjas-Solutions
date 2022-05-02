#include <iostream>
using namespace std;

int main()
{
    int s, e, w, c;
    cin >> s >> e >> w;
    while (s <= e)
    {
        cout << s << " ";
        c = (5.0 / 9) * (s - 32);
        cout << c << endl;
        s = s + w;
    }
    return 0;
}