#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string expression)
{
    stack<char> s1;
    int i = 0;
    while (expression[i] != '\0')
    {
        if (expression[i] == '(')
        {
            s1.push('(');
        }
        else if (expression[i] == ')')
        {
            if (s1.empty() || s1.top() == ')')
            {
                return false;
            }
            if (s1.top() == '(')
            {
                s1.pop();
            }
        }
        i++;
    }
    return s1.empty();
}

int main()
{
    string input;
    cin >> input;
    cout << ((isBalanced(input)) ? "true" : "false");
}