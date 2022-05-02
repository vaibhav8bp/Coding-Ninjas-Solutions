#include <iostream>
using namespace std;

void merge(int input[], int lb, int mid, int ub)
{
    int size = ub - lb + 1;
    int *helperArray = new int[size];
    int i = lb, j = mid + 1, k = 0, m = 0;
    while (i <= mid && j <= ub)
    {
        if (input[i] <= input[j])
        {
            helperArray[k++] = input[i++];
        }
        else
        {
            helperArray[k++] = input[j++];
        }
    }
    while (i <= mid)
    {
        helperArray[k++] = input[i++];
    }
    while (j <= ub)
    {
        helperArray[k++] = input[j++];
    }
    for (i = lb; i <= ub; i++)
    {
        input[i] = helperArray[m++];
    }
    delete[] helperArray;
}

void mergeSortOriginal(int input[], int lb, int ub)
{
    if (lb < ub)
    {
        int mid = (lb + ub) / 2;
        mergeSortOriginal(input, lb, mid);
        mergeSortOriginal(input, mid + 1, ub);
        merge(input, lb, mid, ub);
    }
}

void mergeSort(int input[], int size)
{
    mergeSortOriginal(input, 0, size - 1);
}

int main()
{
    int length;
    cin >> length;
    int *input = new int[length];
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
    }
    mergeSort(input, length);
    for (int i = 0; i < length; i++)
    {
        cout << input[i] << " ";
    }
    delete[] input;
}