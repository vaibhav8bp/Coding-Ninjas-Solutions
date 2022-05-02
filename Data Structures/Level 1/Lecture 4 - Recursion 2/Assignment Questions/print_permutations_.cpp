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
    for (int i = 0; i <= output.size(); i++)
    {
        printPermutationsHelper(input.substr(1), output.substr(0, i) + input[0] + output.substr(i));
    }
}

void printPermutations(string input)
{
    printPermutationsHelper(input, "");
}

int main()
{
    string input;
    cin >> input;
    printPermutations(input);
    return 0;
}