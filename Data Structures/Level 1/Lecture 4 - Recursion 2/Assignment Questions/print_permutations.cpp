#include <iostream>
#include <string>
using namespace std;

void printPermutationsHelper(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    for (int i = 0; i < input.length(); i++)
    {
        string rest = input.substr(0, i) + input.substr(i + 1);
        printPermutationsHelper(rest, output + input[i]);
    }
}

void printPermutations(string input)
{
    return printPermutationsHelper(input, "");
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}