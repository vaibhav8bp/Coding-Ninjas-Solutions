#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkRedundantBrackets(string expression)
{
    stack<char> s1;
    int i = 0;
    while (expression[i] != '\0')
    {
        if (expression[i] != ')')
        {
            s1.push(expression[i]);
        }
        else
        {
            int count = 0;
            while (s1.top() != '(')
            {
                count++;
                s1.pop();
            }
            s1.pop();
            if (count == 0 || count == 1)
            {
                return true;
            }
        }
        i++;
    }
    return false;
}

int main()
{
    string input;
    cin >> input;
    cout << ((checkRedundantBrackets(input)) ? "true" : "false");
}