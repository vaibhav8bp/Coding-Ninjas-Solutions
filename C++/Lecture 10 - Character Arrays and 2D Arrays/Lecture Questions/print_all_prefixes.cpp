#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int i, j, len;
    char string[1000];
    cout << "Enter string :- ";
    cin.getline(string, 1000);
    len = strlen(string);
    cout << "Length of string is :- " << len << endl;
    cout << "All prefixes of " << string << " are :-" << endl;
    for (i = 0; i < len; i++) // in condition we can also write input[i]!=0
    {
        for (j = 0; j <= i; j++)
        {
            cout << string[j];
        }
        cout << endl;
    }
    return 0;
}