#include <iostream>
using namespace std;

void printSubset(int input[], int output[], int size, int output_size)
{
    if (size == 0)
    {
        for (int i = 0; i < output_size; i++)
        {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    printSubset(input + 1, output, size - 1, output_size);
    output[output_size++] = input[0];
    printSubset(input + 1, output, size - 1, output_size);
}

void printSubsetsOfArray(int input[], int size)
{
    int output[1000];
    int output_size = 0;
    printSubset(input, output, size, output_size);
}

int main()
{
    int input[1000], length;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    printSubsetsOfArray(input, length);
}