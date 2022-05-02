#include <iostream>
using namespace std;

bool checkAB(char input[])
{
    if (input[0] == '\0')
    {
        return true;
    }
    if (input[0] != 'a')
    {
        return false;
    }
    if (input[1] == 'b' && input[2] == 'b')
    {
        return checkAB(input + 3);
    }
    return checkAB(input + 1);
}

int main()
{
    char input[100];
    bool ans;
    cin >> input;
    ans = checkAB(input);
    if (ans)
        cout << "true" << endl;
    else
        cout << "false" << endl;
}