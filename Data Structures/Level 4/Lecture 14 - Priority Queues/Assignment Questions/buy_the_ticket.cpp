#include <iostream>
#include <queue>
using namespace std;

int buyTicket(int *arr, int n, int k)
{
    priority_queue<int> pq;
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        q.push(arr[i]);
    }
    int time = 0;
    while (!pq.empty())
    {
        if (q.front() == pq.top())
        {
            if (k == 0)
            {
                return time + 1;
            }
            else
            {
                time++;
                q.pop();
                pq.pop();
                k--;
            }
        }
        else
        {
            q.push(q.front());
            q.pop();
            if (k == 0)
            {
                k = q.size() - 1;
            }
            else
            {
                k--;
            }
        }
    }
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

    cout << buyTicket(arr, n, k);

    delete[] arr;
}