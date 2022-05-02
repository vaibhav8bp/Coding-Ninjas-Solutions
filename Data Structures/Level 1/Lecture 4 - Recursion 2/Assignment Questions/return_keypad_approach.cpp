#include <iostream>
#include <string>
using namespace std;

string number[9] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypad(int num, string output[])
{
    if (num == 0 || num == 1)
    {
        output[0] = "";
        return 1;
    }
    
    int lastDigit = num % 10;
    int remaining = num / 10;

    int smallOutputSize = keypad(remaining, output);

    for (int j = 0; j < number[lastDigit - 2].size() - 1; j++)
    {
        for (int i = 0; i < smallOutputSize; i++)
        {
            output[(j + 1) * (smallOutputSize) + i] = output[i];
        }
    }

    for (int j = 0; j < number[lastDigit - 2].size(); j++)
    {
        for (int i = 0; i < smallOutputSize; i++)
        {
            output[(j) * (smallOutputSize) + i] += number[lastDigit - 2].substr(j, 1);
        }
    }

    return smallOutputSize * number[lastDigit - 2].size();
}

int main()
{
    int num;
    cin >> num;
    string output[10000] = "";
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}