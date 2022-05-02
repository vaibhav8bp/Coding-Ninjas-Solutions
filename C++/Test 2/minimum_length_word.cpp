#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

void minLengthWord(char input[], char output[])
{
    int i, j = 0, k, length = strlen(input), count = INT_MAX;
    char temp[100000];
    for (i = 0; i < length; i++)
    {
        k = 0;
        while (input[j] != 32 && input[j] != '\0')
        {
            temp[k++] = input[j];
            j++;
        }
        temp[k] = '\0';
        if (k < count)
        {
            strcpy(output, temp);
            count = k;
        }
        i = ++j;
    }
}

int main()
{
    char ch[10000], output[10000];
    cin.getline(ch, 10000);
    minLengthWord(ch, output);
    cout << output << endl;
}
