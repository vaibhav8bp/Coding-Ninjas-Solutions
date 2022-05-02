#include <iostream>
using namespace std;
int main()
{
    try
    {
        throw 10;
    }
    catch (double c)
    {
        cout << "integer type exception" << endl;
    }
    catch (...)
    {
        cout << "Default Exception" << endl;
    }
}
/*
Here in the above example, "throw 10" should be Implicitly
get converted to double, but it doesn’t get converted.
Instead it get caught in generic catch block. So Implicit
type casting doesn’t happen for primitive type.
*/