#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra)
{
    if (input.size() <= 1)
    {
        return;
    }
    int lastElement = input.top();
    input.pop();
    reverseStack(input, extra);
    while (!input.empty())
    {
        int temp = input.top();
        extra.push(temp);
        input.pop();
    }
    input.push(lastElement);
    while (!extra.empty())
    {
        int temp = extra.top();
        input.push(temp);
        extra.pop();
    }
}

int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}