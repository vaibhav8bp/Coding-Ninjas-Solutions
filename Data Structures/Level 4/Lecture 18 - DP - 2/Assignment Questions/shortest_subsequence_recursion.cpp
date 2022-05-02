#include <iostream>
using namespace std;

int solve(string s, string v)
{
    if (s.empty())
    {
        return 1095;
    }
    if (v.empty())
    {
        return 1;
    }
    int k = 0;
    while (v[k] != '\0')
    {
        if (v[k] == s[0])
        {
            break;
        }
        k++;
    }
    // a character present in s is not present in v therefore it is the answer itself
    if (k == v.length())
    {
        return 1;
    }
    int exclude = solve(s.substr(1), v);
    int include = 1 + solve(s.substr(1), v.substr(k + 1));
    return min(include, exclude);
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}