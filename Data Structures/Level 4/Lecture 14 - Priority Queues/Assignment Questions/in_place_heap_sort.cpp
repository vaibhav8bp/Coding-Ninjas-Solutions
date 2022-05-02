#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapSort(int *input, int n)
{
    // Up-Heapify
    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (input[parentIndex] > input[childIndex])
            {
                swap(&input[parentIndex], &input[childIndex]);
                childIndex = parentIndex;
            }
            else
            {
                break;
            }
        }
    }
    // Down-Heapify
    int size = n;
    while (size > 1)
    {
        swap(&input[0], &input[size - 1]);
        size--;
        int parentIndex = 0;
        int left_child_Index = (2 * parentIndex + 1);
        int right_child_Index = (2 * parentIndex + 2);
        int minIndex;
        while (left_child_Index < size)
        {
            if (right_child_Index >= size)
            {
                minIndex = left_child_Index;
            }
            else
            {
                minIndex = (input[left_child_Index]) < (input[right_child_Index]) ? (left_child_Index) : (right_child_Index);
            }

            if (input[minIndex] > input[parentIndex])
            {
                break;
            }
            else
            {
                swap(&input[parentIndex], &input[minIndex]);
                parentIndex = minIndex;
            }
            left_child_Index = (2 * parentIndex + 1);
            right_child_Index = (2 * parentIndex + 2);
        }
    }
}

int main()
{
    int size;
    cin >> size;

    int *input = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> input[i];
    }

    heapSort(input, size);

    for (int i = 0; i < size; i++)
    {
        cout << input[i] << " ";
    }

    delete[] input;
}