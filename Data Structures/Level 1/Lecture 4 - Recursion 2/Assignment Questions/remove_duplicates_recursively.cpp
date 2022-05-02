#include <iostream>
using namespace std;

// aabccba

void removeConsecutiveDuplicatesHelper(char *input, int compare1, int compare2, int final)
{
    if (input[compare2] == '\0')
    {
        input[final] = '\0';
        return;
    }
    if (input[compare1] != input[compare2])
    {
        input[final] = input[compare2];
        removeConsecutiveDuplicatesHelper(input, compare2, compare2 + 1, final + 1);
    }
    else
    {
        removeConsecutiveDuplicatesHelper(input, compare1, compare2 + 1, final);
    }
}

void removeConsecutiveDuplicates(char *input)
{
    return removeConsecutiveDuplicatesHelper(input, 0, 1, 1);
}

int main()
{
    char s[100000];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
}