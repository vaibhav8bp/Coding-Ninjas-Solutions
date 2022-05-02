#include <iostream>
#include <cstring>
using namespace std;

// aaabbcddeeeee
// a3b2cd2e5

string getCompressedString(string &input)
{
    int i, len = input.length(), count, j = 0, k = 0;
    for (i = 0; i < len;)
    {
        count = 0;
        while (input[i] == input[j] && input[j] != '\0')
        {
            count++;
            j++;
        }
        input[k++] = input[i];
        if (count > 1)
        {
            input[k++] = count + 48; // 48 is used for ascii table.
        }
        i = j;
    }
    input.erase(k);
    // This does not work in case of C++
    // input[k]='\0';
    return input;
}

int main()
{
    int size = 1e6;
    string str;
    cin >> str;
    str = getCompressedString(str);
    // cout << str << endl;
}