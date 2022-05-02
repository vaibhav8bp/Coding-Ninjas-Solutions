#include <iostream>
#include <string.h>
using namespace std;

void printAllPossibleCodesHelper(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    int first = input[0] - 48;
    char first_char = first + 'a' - 1;
    int second = first * 10 + input[1] - 48;
    char second_char = second + 'a' - 1;
    printAllPossibleCodesHelper(input.substr(1), output + first_char);
    if (second >= 10 && second <= 26)
    {
        printAllPossibleCodesHelper(input.substr(2), output + second_char);
    }
}

void printAllPossibleCodes(string input)
{
    printAllPossibleCodesHelper(input, "");
}

int main()
{
    string input;
    cin >> input;
    printAllPossibleCodes(input);
    return 0;
}