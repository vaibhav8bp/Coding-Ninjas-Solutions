#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

int stringToNumberHelper(char input[], int power)
{
    if (input[0] == '\0')
    {
        return 0;
    }
    int number_value = input[strlen(input) - 1] - 48;
    input[strlen(input) - 1] = '\0';
    return number_value * pow(10, power) + stringToNumberHelper(input, power + 1);
}

int stringToNumber(char input[])
{
    return stringToNumberHelper(input, 0);
}

int main()
{
    char input[50];
    cin >> input;
    cout << stringToNumber(input) << endl;
}