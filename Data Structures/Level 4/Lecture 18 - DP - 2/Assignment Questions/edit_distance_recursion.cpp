#include <cstring>
#include <iostream>
using namespace std;

int editDistance(string s1, string s2)
{
    // Base Case
    if (s1.empty())
    {
        return s2.length();
    }
    else if (s2.empty())
    {
        return s1.length();
    }
    else if (s1 == s2)
    {
        return 0;
    }

    if (s1[0] == s2[0])
    {
        return editDistance(s1.substr(1), s2.substr(1));
    }
    int answer;
    int a = editDistance(s1.substr(1), s2);
    int b = editDistance(s1, s2.substr(1));
    int c = editDistance(s1.substr(1), s2.substr(1));

    answer = min(a, min(b, c)) + 1;
    return answer;
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2);
}