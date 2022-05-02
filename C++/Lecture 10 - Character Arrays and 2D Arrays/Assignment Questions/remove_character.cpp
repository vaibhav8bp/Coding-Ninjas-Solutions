#include <iostream>
#include <cstring>
using namespace std;

void removeAllOccurrencesOfChar(char input[], char c)
{
    int i, j, length = strlen(input), temp, occurence = 0;
    for (i = 0; i < length; i++)
    {
        if (input[i] != c)
        {
            input[occurence++] = input[i];
        }
    }
    input[occurence] = '\0';
}

int main()
{
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    char c;
    cin >> c;
    removeAllOccurrencesOfChar(str, c);
    cout << str;
}