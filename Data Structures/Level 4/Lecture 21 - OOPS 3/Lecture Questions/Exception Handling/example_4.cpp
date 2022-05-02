#include <iostream>
using namespace std;
int main()
{
    try
    {
        char c = 'a';
        throw c;
    }
    catch (int x)
    {
        cout << "integer exception" << endl;
    }
}

// If the catch block for any throw doesn’t exists it will terminate abruptly.