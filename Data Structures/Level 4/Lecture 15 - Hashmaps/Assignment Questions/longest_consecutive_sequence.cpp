#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;

/*
10
9 1 8 6 3 4 2 7 10 15
*/

vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> sequence;
    for (int i = 0; i < n; i++)
    {
        sequence[arr[i]] = true;
    }
    int maxLength = 0;
    int start, finalStart;
    int end, finalEnd;
    int currentSmallerIndex = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (sequence.count(arr[i] - 1))
        {
            continue;
        }
        int currentLength = 0;
        start = arr[i];
        end = arr[i];
        currentLength = 1;
        while (sequence.count(arr[i] + currentLength) != 0)
        {
            end = arr[i] + currentLength;
            currentLength++;
        }
        if (currentLength > maxLength)
        {
            maxLength = currentLength;
            finalStart = start;
            finalEnd = end;
            currentSmallerIndex = i;
        }
        else if (currentLength == maxLength)
        {
            if (i < currentSmallerIndex)
            {
                finalStart = start;
                finalEnd = end;
                currentSmallerIndex = i;
            }
        }
    }
    vector<int> answer;
    if (finalStart == finalEnd)
    {
        answer.push_back(finalStart);
    }
    else
    {
        answer.push_back(finalStart);
        answer.push_back(finalEnd);
    }
    return answer;
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

    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    cout << ans[0];
    if (ans.size() > 1)
    {
        cout << " " << ans[ans.size() - 1];
    }

    delete[] arr;
}