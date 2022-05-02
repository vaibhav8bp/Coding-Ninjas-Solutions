#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int kthLargest(int *arr, int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int count = 0;
    while (count < k - 1)
    {
        pq.pop();
        count++;
    }
    return pq.top();
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;
    cin >> k;

    cout << kthLargest(arr, n, k);

    delete[] arr;
}