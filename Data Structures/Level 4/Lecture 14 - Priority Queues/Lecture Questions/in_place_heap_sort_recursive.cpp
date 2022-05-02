#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *input, int size, int index)
{
    int smallest = index;
    int l = (2 * index) + 1;
    int r = (2 * index) + 2;

    if (l < size && input[l] < input[smallest])
    {
        smallest = l;
    }
    if (r < size && input[r] < input[smallest])
    {
        smallest = r;
    }
    if (smallest != index)
    {
        swap(&input[index], &input[smallest]);
        heapify(input, size, smallest);
    }
}

void heapSort(int *input, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(input, size, i);
    }
    for (int i = size - 1; i > 0; i--)
    {
        swap(&input[0], &input[i]);
        heapify(input, i, 0);
    }
}

int main()
{
    int n;
    cout << "Enter array length : " << endl;
    cin >> n;
    int b[n];
    cout << "Enter " << n << " elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    cout << "Before Sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    heapSort(b, n);
    cout << "After Sorting : " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}