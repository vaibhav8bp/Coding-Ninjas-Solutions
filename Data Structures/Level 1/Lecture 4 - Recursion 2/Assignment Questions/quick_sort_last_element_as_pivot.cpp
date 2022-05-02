#include <iostream>
using namespace std;

/*

6
2 6 8 5 4 3

*/

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // pivot
    int next_small = low;  // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot)
        {
            // increment index of smaller element
            swap(&arr[next_small], &arr[j]);
            next_small++;
        }
    }
    swap(&arr[next_small], &arr[high]);
    cout << next_small << endl;
    return next_small;
}

void quick_Sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_Sort(arr, low, pi - 1);
        quick_Sort(arr, pi + 1, high);
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
