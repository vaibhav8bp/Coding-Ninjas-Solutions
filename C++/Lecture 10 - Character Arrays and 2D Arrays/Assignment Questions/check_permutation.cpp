#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

bool isPermutation(char input1[], char input2[])
{
    if (strlen(input1) != strlen(input2))
    {
        return false;
    }
    else
    {
        int i, j, length1 = strlen(input1), length2 = strlen(input2);
        for (i = 0; i < length1; i++)
        {
            for (j = 0; j < length2; j++)
            {
                if (input1[i] == input2[j])
                {
                    input2[j] = CHAR_MIN;
                    break;
                }
            }
            if (j == strlen(input2))
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