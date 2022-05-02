#include <iostream>
#include <string>
#include <stack>
using namespace std;

int countBracketReversals(string input)
{
    int i = 0;
    stack<char> q1;
    int answer = 0;
    if (input.length() % 2 != 0)
    {
        return -1;
    }
    while (input[i] != '\0')
    {
        if (input[i] == '{')
        {
            q1.push(input[i]);
        }
        else
        {
            if (!q1.empty() && q1.top() == '{')
            {
                q1.pop();
            }
            else
            {
                q1.push(input[i]);
            }
        }
        i++;
    }

    while (!q1.empty())
    {
        char c1 = q1.top();
        q1.pop();
        char c2 = q1.top();
        q1.pop();
        if (c1 == c2)
        {
            answer += 1;
        }
        else
        {
            answer += 2;
        }
    }
    return answer;
}

int main()
{
    string input;
    cin >> input;
    cout << countBracketReversals(input);
}