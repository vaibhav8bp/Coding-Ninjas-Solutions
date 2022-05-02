#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low], start = low, end = high;
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            swap(&arr[start], &arr[end]);
        }
    }
    swap(&arr[low], &arr[end]);
    return end;
}

void quick_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int loc = partition(arr, low, high);
        quick_Sort(arr, low, loc - 1);
        quick_Sort(arr, loc + 1, high);
    }
}
void quickSort(int input[], int size)
{
    quick_Sort(input, 0, size - 1);
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
