#include <iostream>
#include <string>
using namespace std;

string phone[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypadHelper(int num, string output)
{
    if (num == 0 || num == 1)
    {
        cout << output << endl;
        return;
    }
    int smallnum = num / 10;
    int last = num % 10;
    for (int i = 0; i < phone[last - 2].size(); i++)
    {
        printKeypadHelper(smallnum, phone[last - 2].substr(i, 1) + output);
    }
}

void printKeypad(int num)
{
    printKeypadHelper(num, "");
}

int main()
{
    int num;
    cin >> num;
    string output = "";
    printKeypad(num);
    return 0;
}