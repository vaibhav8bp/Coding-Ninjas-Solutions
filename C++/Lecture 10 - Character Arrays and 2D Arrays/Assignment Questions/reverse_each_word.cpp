#include <iostream>
#include <cstring>
using namespace std;

void reverse_string(char input[], int start, int end)
{
    int temp;
    while (start < end)
    {
        temp = input[start];
        input[start] = input[end];
        input[end] = temp;
        start++;
        end--;
    }
}

void reverseEachWord(char input[])
{
    int i = 0, j = 0;

    while (input[i] != '\0')
    {
        while (input[j] != 32 && input[j] != '\0')
        {
            j++;
        }
        reverse_string(input, i, j - 1);
        i = ++j;
    }
}

int main()
{
    int size = 1e6;
    char str[size];
    cin.getline(str, size);
    reverseEachWord(str);
    cout << str;
}