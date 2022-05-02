#include <iostream>
#include <unordered_map>
using namespace std;

int pairSum(int *arr, int n)
{
    unordered_map<int, int> sum;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int complement = -arr[i];
        if (sum.find(complement) != sum.end())
        {
            count += sum[complement];
        }
        sum[arr[i]]++;
    }
    return count;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << pairSum(arr, n);

    delete[] arr;
}
