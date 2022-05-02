#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int *input, int size, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(input[i]);
    }
    int current = 0;
    for (int i = k; i < size; i++)
    {
        input[current++] = pq.top();
        pq.pop();
        pq.push(input[i]);
    }
    while (!pq.empty())
    {
        input[current++] = pq.top();
        pq.pop();
    }
}

int main()
{
    int input[] = {12, 15, 6, 7, 9};
    int k = 3;
    kSortedArray(input, 5, k);
    for (int i = 0; i < 5; i++)
    {
        cout << input[i] << endl;
    }
    return 0;
}