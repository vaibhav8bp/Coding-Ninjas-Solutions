#include <iostream>
using namespace std;

int main()
{
    int count_l = 0, count_d = 0, count_w = 0;
    char c;
    c = cin.get();
    while (c != '$')
    {
        if (c >= 97 && c <= 122)
        {
            count_l++;
        }
        else if (c >= 48 && c <= 57)
        {
            count_d++;
        }
        else if (c == 32 || c == '\n' || c == '\t')
        {
            count_w++;
        }
        c = cin.get();
    }
    cout << count_l << " " << count_d << " " << count_w << endl;
    return 0;
}