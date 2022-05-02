#include <iostream>
using namespace std;

int length(char input[])
{
    if (input[0] == '\0')
    {
        return 0;
    }
    return 1 + length(input + 1);
}
int main()
{
    char input[50];
    cout << "Enter a string : - ";
    cin.getline(input, 50);
    cout << "Length of " << input << " is :- " << length(input);
    return 0;
}