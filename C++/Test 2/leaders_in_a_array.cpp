#include <iostream>
#include <climits>
using namespace std;

void Leaders(int *arr, int len)
{
    int answer[len];
    int m = INT_MIN, k = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (arr[i] >= m)
        {
            answer[k++] = arr[i];
        }
        m = max(arr[i], m);
    }
    for (int i = k - 1; i >= 0; i--)
    {
        cout << answer[i] << " ";
    }
}

int main()
{
    int len;
    cin >> len;
    int *arr = new int[len + 1];

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }
    Leaders(arr, len);
}