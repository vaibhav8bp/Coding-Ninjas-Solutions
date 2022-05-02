#include <iostream>
#include <algorithm>
using namespace std;

int pairSum(int *arr, int n, int num)
{
    int i = 0, j = n - 1, count = 0;
    while (i < j)
    {
        if (arr[i] + arr[j] == num)
        {
            int elementatStart = arr[i];
            int elementatEnd = arr[j];
            if (elementatStart == elementatEnd)
            {
                count += ((j - i) * (j - i + 1)) / 2;
                return count;
            }
            int tempstartindex = i + 1, tempendindex = j - 1;
            while (tempstartindex <= tempendindex && arr[tempstartindex] == elementatStart)
            {
                tempstartindex++;
            }
            while (tempendindex >= tempstartindex && arr[tempendindex] == elementatEnd)
            {
                tempendindex--;
            }
            int duplicate_from_start = tempstartindex - i;
            int duplicate_from_end = j - tempendindex;
            count += (duplicate_from_end * duplicate_from_start);
            i = tempstartindex;
            j = tempendindex;
        }
        else if (arr[i] + arr[j] < num)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return count;
}

int tripletSum(int *arr, int n, int num)
{
    sort(arr, arr + n);
    int count = 0;
    for (int i = 0; i < n - 2; i++)
    {
        count += pairSum(arr + i + 1, n - i - 1, num - arr[i]);
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int size;
        int x;
        cin >> size;
        int *input = new int[size];
        for (int i = 0; i < size; i++)
        {
            cin >> input[i];
        }
        cin >> x;
        cout << tripletSum(input, size, x) << endl;
        delete[] input;
    }
    return 0;
}