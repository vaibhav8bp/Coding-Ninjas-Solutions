#include <iostream>
#include <string>
using namespace std;

int returnPermutations(string input, string output[])
{
    if (input.empty())
    {
        output[0] = "";
        return 1;
    }
    int k = 0;
    for (int i = 0; i < input.size(); i++)
    {
        string rest = input.substr(0, i) + input.substr(i + 1);
        string smalloutput[10000];
        int smallsize = returnPermutations(rest, smalloutput);
        for (int j = 0; j < smallsize; j++)
        {
            output[k++] = input[i] + smalloutput[j];
        }
    }
    return k;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = returnPermutations(input, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}