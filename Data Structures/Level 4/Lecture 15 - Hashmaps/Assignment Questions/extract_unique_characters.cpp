#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

string uniqueChar(string str)
{
    int count = 0;
    unordered_map<char, int> h;
    for (int i = 0; i < str.length(); i++)
    {
        if (h.count(str[i]) == 0)
        {
            str[count++] = str[i];
            h[str[i]]++;
        }
    }
    str.erase(count);
    return str;
}

int main()
{
    string str;
    cin >> str;
    cout << uniqueChar(str) << endl;
}