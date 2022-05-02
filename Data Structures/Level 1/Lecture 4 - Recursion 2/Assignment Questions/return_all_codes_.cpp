#include <iostream>
#include <string.h>
using namespace std;

int getCodes(string input, string output[10000])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    int first = input[0] - 48;
    char first_char = first + 'a' - 1;
    int second = first * 10 + input[1] - 48;
    char second_char = second + 'a' - 1;
    string smalloutput1[10000];
    string smalloutput2[10000];
    int size1 = getCodes(input.substr(1), smalloutput1);
    int size2 = 0;

    if (input[1] != '\0')
    {
        if (second >= 10 && second <= 26)
        {
            size2 = getCodes(input.substr(2), smalloutput2);
        }
    }
    int k = 0, i;
    for (i = 0; i < size1; i++)
    {
        output[k++] = first_char + smalloutput1[i];
    }
    for (i = 0; i < size2; i++)
    {
        output[k++] = second_char + smalloutput2[i];
    }
    return size1 + size2;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = getCodes(input, output);

    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }

    return 0;
}