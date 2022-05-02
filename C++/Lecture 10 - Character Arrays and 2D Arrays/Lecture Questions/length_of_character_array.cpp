#include <iostream>
using namespace std;

int main()
{
    char name[1000];
    cin.getline(name, 10);
    cout << name << endl;
    char c;
    int count = 0, i = 0;
    for (c = name[i]; c != '\0'; c = name[++i])
    {
        count++;
    }
    cout << count;
    return 0;
}