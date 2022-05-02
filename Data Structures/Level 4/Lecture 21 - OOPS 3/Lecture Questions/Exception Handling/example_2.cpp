#include <iostream>
using namespace std;
int main()
{
    try
    {
        throw 'c';
    }
    catch (char c)
    {
        cout << "character type exception" << endl;
    }
    catch (...)
    {
        cout << "Default Exception" << endl;
    }
}

/*
We can see here that catch(...) catches all type of exceptions.
Few things about all catch blocks :
a) If there are multiple catch blocks, all catch block should be placed last.
b) Since all catch block (generic catch) is placed last, if any specific type exception
occurs, it will try to find its specific catch block and if it is not found then it will
go to the generic catch block.
*/