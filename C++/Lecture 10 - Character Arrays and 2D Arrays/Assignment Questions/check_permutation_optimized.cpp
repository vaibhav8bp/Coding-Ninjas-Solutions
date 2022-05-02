#include <iostream>
#include <cstring>
using namespace std;

bool isPermutation(char input1[], char input2[])
{
    if (strlen(input1) != strlen(input2))
    {
        return false;
    }
    else
    {
        int frequency[256] = {0}, i, a, length = strlen(input1);
        for (i = 0; i < length; i++)
        {
            a = input1[i];
            frequency[a]++;
            a = input2[i];
            frequency[a]--;
        }

        for (i = 0; i < 256; i++)
        {
            if (frequency[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    int size = 1e6;
    char str1[size];
    char str2[size];
    cin >> str1 >> str2;
    cout << (isPermutation(str1, str2) ? "true" : "false");
}