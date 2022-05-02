#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int input[], int lb, int ub)
{
    int count_small = 0, pivot = input[lb], i, start = lb, end = ub, pivotIndex;
    for (i = lb + 1; i <= ub; i++)
    {
        if (input[i] <= pivot)
        {
            count_small++;
        }
    }
    pivotIndex = lb + count_small;
    swap(&input[lb], &input[pivotIndex]);
    start = lb, end = ub;
    while (start < pivotIndex && end > pivotIndex)
    {
        if (input[start] <= pivot)
        {
            start++;
        }
        else if (input[end] > pivot)
        {
            end--;
        }
        else
        {
            swap(&input[start], &input[end]);
            start++;
            end--;
        }
    }
    return pivotIndex;
}

void quickSortOriginal(int input[], int lb, int ub)
{
    if (lb >= ub)
    {
        return;
    }
    else
    {
        int loc = partition(input, lb, ub);
        quickSortOriginal(input, lb, loc - 1);
        quickSortOriginal(input, loc + 1, ub);
    }
}

void quickSort(int input[], int size)
{
    quickSortOriginal(input, 0, size - 1);
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
    quickSort(input, n);
    for (int i = 0; i < n; i++)
    {
        cout << input[i] << " ";
    }
    delete[] input;
}