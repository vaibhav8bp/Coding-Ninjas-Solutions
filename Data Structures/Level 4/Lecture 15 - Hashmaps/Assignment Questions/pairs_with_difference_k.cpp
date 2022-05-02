#include <iostream>
#include <unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int n, int k)
{
    unordered_map<int, int> sum;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int complement = arr[i] - k;
        int complement1 = arr[i] + k;
        if (sum.find(complement) != sum.end())
        {
            count += sum[complement];
        }
        if (sum.find(complement1) != sum.end() && complement != complement1) // For 0
        {
            count += sum[complement1];
        }
        sum[arr[i]]++;
    }
    return count;
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

    int k;
    cin >> k;

    cout << getPairsWithDifferenceK(input, n, k);

    delete[] input;
}