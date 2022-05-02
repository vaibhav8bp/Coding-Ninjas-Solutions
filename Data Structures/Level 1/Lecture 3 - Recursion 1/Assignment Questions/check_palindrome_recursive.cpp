#include <iostream>
#include <cstring>
using namespace std;

bool checkPalindrome(char input[])
{
    int length = strlen(input);
    if (length == 0 || length == 1)
    {
        return true;
    }
    if (input[0] == input[length - 1])
    {
        input[length - 1] = '\0';
        return checkPalindrome(input + 1);
    }
    else
    {
        return false;
    }
}

int main()
{
    char input[50];
    cin >> input;
    if (checkPalindrome(input))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}