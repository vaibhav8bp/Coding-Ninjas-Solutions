#include <iostream>
#include <string>
using namespace std;

void printSubsequence(string input, string output)
{
    if (input.empty())
    {
        cout << output << endl;
        return;
    }
    printSubsequence(input.substr(1), output);
    printSubsequence(input.substr(1), output + input[0]);
}

int main()
{
    string input;
    getline(cin, input);
    string output = "";
    printSubsequence(input, output);
    return 0;
}