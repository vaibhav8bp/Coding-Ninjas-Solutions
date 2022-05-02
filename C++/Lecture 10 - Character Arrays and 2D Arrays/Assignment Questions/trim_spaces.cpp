#include <iostream>
#include <cstring>
using namespace std;

void trimSpaces(char input[])
{
    int next_space = 0, temp;
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] != 32)
        {
            temp = input[i];
            input[i] = input[next_space];
            input[next_space] = temp;
            next_space++;
        }
    }
    input[next_space]='\0';
}

int main()
{
    char input[1000000];
    cin.getline(input, 1000000);
    trimSpaces(input);
    cout << input << endl;
}