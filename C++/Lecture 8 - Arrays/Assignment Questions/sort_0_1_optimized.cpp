#include <iostream>
using namespace std;

void sortZeroesAndOne(int *input, int size)
{
    int i = 0, next_zero = 0, temp;
    for (int i = 0; i < size; i++)
    {
        if (input[i] == 0)
        {
            temp = input[i];
            input[i] = input[next_zero];
            input[next_zero] = temp;
            next_zero++;
        }
    }
}

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int size;
        cin >> size;
        int *input = new int[size];
        for (int i = 0; i < size; ++i)
        {
            cin >> input[i];
        }
        sortZeroesAndOne(input, size);
        for (int i = 0; i < size; ++i)
        {
            cout << input[i] << " ";
        }
        cout << endl;
        delete[] input;
    }
    return 0;
}