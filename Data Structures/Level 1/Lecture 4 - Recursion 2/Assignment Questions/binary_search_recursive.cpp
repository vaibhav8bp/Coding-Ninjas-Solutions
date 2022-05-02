#include <iostream>
using namespace std;

int binarySearchHelper(int input[], int low, int high, int element)
{
    if (low == high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (input[mid] == element)
    {
        return mid;
    }

    else if (input[mid] < element)
    {
        return binarySearchHelper(input, mid + 1, high, element);
    }

    else
    {
        return binarySearchHelper(input, low, mid - 1, element);
    }
}

int binarySearch(int input[], int size, int element)
{
    return binarySearchHelper(input, 0, size - 1, element);
}

int main()
{
    int input[100000], length, element, ans;
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cin >> input[i];
        ;
    }
    cin >> element;
    ans = binarySearch(input, length, element);
    cout << ans << endl;
}