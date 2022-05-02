#include <iostream>
#include <cstring>
using namespace std;

void shiftAndReplaceByStar(char input[], int length)
{
    if (length == -1)
    {
        input[0] = '*';
        return;
    }
    input[length + 1] = input[length];
    shiftAndReplaceByStar(input, length - 1);
}

void pairStar(char input[])
{
    if (input[0] == '\0' || input[1] == '\0')
    {
        return;
    }
    if (input[0] == input[1])
    {
        shiftAndReplaceByStar(input + 1, strlen(input) - 1);
    }
    pairStar(input + 1);
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
}