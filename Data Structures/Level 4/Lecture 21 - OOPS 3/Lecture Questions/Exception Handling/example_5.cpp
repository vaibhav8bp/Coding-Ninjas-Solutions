#include <iostream>
using namespace std;

int main()
{
    try
    {
        try
        {
            throw 20;
        }
        catch (int n)
        {
            cout << "Inner catch " << n << endl;
            throw; // Re-throwing an exception
        }
    }
    catch (int n)
    {
        cout << "Outer catch " << n << endl;
    }
}

/*
A function can also re-throw a function using same "throw".
A function can handle a part and can ask the caller to
handle remaining.
*/