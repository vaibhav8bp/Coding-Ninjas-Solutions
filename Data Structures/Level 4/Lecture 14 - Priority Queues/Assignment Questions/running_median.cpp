#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

void findMedian(int *arr, int n)
{
    if (n == 0)
    {
        return;
    }
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    max_heap.push(arr[0]);
    cout << max_heap.top() << " ";
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max_heap.top())
        {
            min_heap.push(arr[i]);
        }
        else
        {
            max_heap.push(arr[i]);
        }
        if (abs(min_heap.size() - max_heap.size()) > 1)
        {
            if (max_heap.size() > min_heap.size())
            {
                int top = max_heap.top();
                max_heap.pop();
                min_heap.push(top);
            }
            else
            {
                int top = min_heap.top();
                min_heap.pop();
                max_heap.push(top);
            }
        }
        int median;
        if (max_heap.size() > min_heap.size())
        {
            median = max_heap.top();
        }
        else if (max_heap.size() < min_heap.size())
        {
            median = min_heap.top();
        }
        else
        {
            median = (min_heap.top() + max_heap.top()) / 2;
        }
        cout << median << " ";
    }
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

    findMedian(arr, n);

    delete[] arr;
}