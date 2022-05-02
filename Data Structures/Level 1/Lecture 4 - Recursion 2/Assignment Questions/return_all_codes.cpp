#include <iostream>
#include <string.h>
using namespace std;

// int getCodes(string input, string output[10000])
// {
//     if (input.empty())
//     {
//         output[0] = "";
//         return 1;
//     }
//     int num = input[0] - 48;
//     char ch = num + 'a' - 1;
//     int size1 = getCodes(input.substr(1), output);
//     for (int i = 0; i < size1; i++)
//     {
//         output[i] = ch + output[i];
//     }
//     int size2 = 0;
//     if (input[1] != '\0')
//     {
//         num = num * 10 + input[1] - 48;
//         ch = num + 'a' - 1;
//         if (num >= 10 && num <= 26)
//         {
//             size2 = getCodes(input.substr(2), output + size1);
//             for (int i = 0; i < size2; i++)
//             {
//                 output[i + size1] = ch + output[i + size1];
//             }
//         }
//     }
//     return size1 + size2;
// }

int getCodes(string input, string output[1000])
{
    if (input[0] == '\0')
    {
        output[0] = "";
        return 1;
    }
    char z = input[0] + 48;
    int res1 = 0, res2 = 0;
    res1 = getCodes(input.substr(1), output);
    for (int i = 0; i < res1; i++)
    {
        output[i] = z + output[i];
    }
    if (input.length() > 1)
    {
        int y = (input[0] - 48) * 10 + (input[1] - 48);
        if (y >= 10 && y <= 26)
        {
            char x = 96 + (input[0] - 48) * 10 + (input[1] - 48);
            res2 = getCodes(input.substr(2), output + res1);
            for (int j = res1; j < res1 + res2; j++)
            {
                output[j] = x + output[j];
            }
        }
    }
    return res1 + res2;
}

int main()
{
    string input;
    cin >> input;
    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}