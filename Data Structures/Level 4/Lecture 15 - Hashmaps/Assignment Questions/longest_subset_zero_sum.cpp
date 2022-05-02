#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    unordered_map<int, int> subset;
    int sum = 0;
    int maxLength = 0;
    int previousIndex;
    int currentIndex;
    int currentLength;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            currentLength = i + 1;
            maxLength = currentLength;
        }
        else if (subset.count(sum))
        {
            currentIndex = i;
            previousIndex = subset[sum];
            currentLength = currentIndex - previousIndex;
            if (currentLength > maxLength)
            {
                maxLength = currentLength;
            }
        }
        else
        {
            subset[sum] = i;
        }
    }
    return maxLength;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    cout << lengthOfLongestSubsetWithZeroSum(arr, size);

    delete[] arr;
}