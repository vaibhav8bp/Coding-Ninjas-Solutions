#include <iostream>
using namespace std;

int allIndexesHelper(int input[], int size, int x, int output[], int start, int output_size)
{
    if (size == 0)
    {
        return output_size;
    }
    if (input[0] == x)
    {
        output[output_size++] = start;
    }
    return allIndexesHelper(input + 1, size - 1, x, output, start + 1, output_size);
}

int allIndexes(int input[], int size, int x, int output[])
{
    return allIndexesHelper(input, size, x, output, 0, 0);
}

int main()
{
    int n;
    cin >> n;
    int *input = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> input[i];
    }
    int x;
    cin >> x;
    int *output = new int[n];
    int size = allIndexes(input, n, x, output);
    for (int i = 0; i < size; i++)
    {
        cout << output[i] << " ";
    }
    delete[] input;
    delete[] output;
}