#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<char> s;

    s.push(97);  //a
    s.push(98);  //b
    s.push(99);  //c
    s.push(100); //d
    s.push(101); //e
    s.push(102); //f
    s.push(103); //g

    cout << s.top() << endl;

    s.pop();
    s.pop();
    s.pop();

    cout << s.size() << endl;

    return 0;
}