#include <iostream>
using namespace std;

int main()
{
    int i = 0, j, length = 0;
    char original[1000], temp;
    cout << "Enter a string : - ";
    cin.getline(original, 1000);
    cout << "Original string : " << original << endl;
    for (i = 0; original[i] != '\0'; i++)
    {
        length++;
    }
    cout << "Length of string is :- " << length << endl;
    i = 0;
    j = length - 1;
    while (i < j)
    {
        temp = original[i];
        original[i] = original[j];
        original[j] = temp;
        i++;
        j--;
    }
    cout << "Reversed string is :- " << original << endl;
    return 0;
}