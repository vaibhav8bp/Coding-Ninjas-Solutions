#include <iostream>
using namespace std;

void printSubsetSumToK_Helper(int input[], int start_index, int output_size, int size, int k, int output[])
{
    if (start_index == size)
    {
        if (k == 0)
        {
            for (int i = 0; i < output_size; i++)
            {
                cout << output[i] << " ";
            }
            cout << endl;
            return;
        }
        else
        {
            return;
        }
    }
    printSubsetSumToK_Helper(input, start_index + 1, output_size, size, k, output);
    output[output_size++] = input[start_index];
    printSubsetSumToK_Helper(input, start_index + 1, output_size, size, k - input[start_index], output);
}

void printSubsetSumToK(int input[], int size, int k)
{
    int *output = new int[1000];
    printSubsetSumToK_Helper(input, 0, 0, size, k, output);
}

int main()
{
    int input[1000], length, k;
    cin >> length;
    for (int i = 0; i < length; i++)
        cin >> input[i];
    cin >> k;
    printSubsetSumToK(input, length, k);
}