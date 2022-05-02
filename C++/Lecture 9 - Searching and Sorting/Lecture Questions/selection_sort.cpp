#include <iostream>
using namespace std;

int minimum(int a[], int start, int n)
{
    int min = a[start], i, j = start;
    for (i = start + 1; i < n; i++)
    {
        if (min > a[i])
        {
            min = a[i];
            j = i;
        }
    }
    return j;
}

void selection_sort(int a[], int n)
{
    int start, i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        start = i;
        j = minimum(a, start, n);
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    }
}

int main()
{
    int a[10000];
    int n, i;
    cout << "Enter the number of elements you want in the array\n";
    cin >> n;
    cout << "Enter " << n << " elements\n";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    selection_sort(a, n);
    cout << "Sorted array :-\n";
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}