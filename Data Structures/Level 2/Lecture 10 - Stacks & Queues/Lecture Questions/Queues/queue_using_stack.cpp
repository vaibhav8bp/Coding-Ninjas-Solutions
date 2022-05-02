#include <iostream>
using namespace std;
#include <stack>

template <typename T>

class queue
{
    stack<T> s1, s2;

public:
    queue()
    {
        while (!s1.empty())
        {
            s1.pop();
        }
        while (!s2.empty())
        {
            s2.pop();
        }
    }
    void enqueue(T data)
    {
        s1.push(data);
    }
    void dequeue()
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int getSize()
    {
        return s1.size();
    }
    bool isEmpty()
    {
        return s1.empty();
    }
    T front()
    {
        if (s1.empty())
        {
            return 0;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        T temp = s2.top();
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
        return temp;
    }
};

int main()
{
    queue<char> q1;

    q1.enqueue(97);  // a
    q1.enqueue(98);  // b
    q1.enqueue(99);  // c
    q1.enqueue(100); // d
    q1.enqueue(101); // e
    q1.enqueue(102); // f
    q1.enqueue(103); // g
    q1.enqueue(104); // h

    q1.dequeue();
    q1.dequeue();
    q1.dequeue();

    cout << q1.front() << endl;
    cout << q1.getSize() << endl;
    cout << q1.isEmpty() << endl;

    return 0;
}