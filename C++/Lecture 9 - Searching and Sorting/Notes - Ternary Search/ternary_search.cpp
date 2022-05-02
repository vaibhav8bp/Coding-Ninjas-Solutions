#include <iostream>
using namespace std;

int ternary_search(int a[], int n, int key)
{
    int low = 0, high = n - 1, mid1, mid2;
    while (low <= high)
    {
        mid1 = low + (high - low) / 3;
        mid2 = high - (high - low) / 3;
        if (a[mid1] == key)
        {
            return mid1;
        }
        else if (a[mid2] == key)
        {
            return mid2;
        }
        else if (a[mid1] > key)
        {
            high = mid1 - 1;
        }
        else if (a[mid2] < key)
        {
            low = mid2 + 1;
        }
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }
    return -1;
}
int main()
{
    int a[100];
    int i, n, key;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> key;
    cout << ternary_search(a, n, key);
    return 0;
}