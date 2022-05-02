#include <iostream>
#include <cstring>
using namespace std;

void shift(char input[], int length)
{
    if (length < 0)
    {
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        return;
    }
    input[length + 2] = input[length];
    shift(input, length - 1);
}

void replacePi(char input[])
{
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }
    if (input[0] == 'p' && input[1] == 'i')
    {
        shift(input, strlen(input));
        replacePi(input + 4);
    }
    else
    {
        replacePi(input + 1);
    }
}

int main()
{
    char input[10000];
    cin.getline(input, 10000);
    replacePi(input);
    cout << input << endl;
}