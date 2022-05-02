#include <iostream>
using namespace std;

bool split_array_original(int *input, int size, int start_index, int left_sum, int right_sum)
{
    if (start_index == size)
    {
        return left_sum == right_sum;
    }
    if (input[start_index] % 5 == 0)
    {
        left_sum += input[start_index];
    }
    else if (input[start_index] % 3 == 0)
    {
        right_sum += input[start_index];
    }
    else
    {
        bool left_answer = split_array_original(input, size, start_index + 1, left_sum + input[start_index], right_sum);
        bool right_answer = split_array_original(input, size, start_index + 1, left_sum, right_sum + input[start_index]);
        return left_answer || right_answer;
    }
    return split_array_original(input, size, start_index + 1, left_sum, right_sum);
}

bool splitArray(int *input, int size)
{
    return split_array_original(input, size, 0, 0, 0);
}

int main()
{
    int size;
    cin >> size;
    int *input = new int[1 + size];
    for (int i = 0; i < size; i++)
        cin >> input[i];

    if (splitArray(input, size))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}
