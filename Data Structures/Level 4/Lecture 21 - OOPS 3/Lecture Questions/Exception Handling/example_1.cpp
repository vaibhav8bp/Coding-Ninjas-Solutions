#include <iostream>
using namespace std;

int main()
{
    int x = 1;
    cout << "Before try" << endl;
    try
    {
        cout << "Inside try \n";
        if (x < 0)
        {
            throw x;
            cout << "After throw" << endl;
        }
    }
    catch (int x)
    {
        cout << "Exception Caught" << endl;
    }
    cout << "After catch" << endl;
}

/*
In the above example we can see the normal flow of throw, catch block.
We can observe that after the exception is thrown, the remaining try block after throw
statement is not executed, instead program control goes to catch and never comes back.
But all the code below the catch block is executed.
So to conclude code after throw is never executed but all the code after catch gets
executed.
*/