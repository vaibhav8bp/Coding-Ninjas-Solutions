#include <iostream>
#include <cstring>
using namespace std;

void removeConsecutiveDuplicates(char input[])
{
    int i = 1, j = 1, length = strlen(input);
    char last_char = input[0];
    while (i < length)
    {
        if (input[i] != last_char)
        {
            input[j++] = input[i];
            last_char = input[i];
        }
        i++;
    }
    input[j] = '\0';
}

int main()
{
    int size = 1e6;
    char str[size];
    cin >> str;
    removeConsecutiveDuplicates(str);
    cout << str;
}