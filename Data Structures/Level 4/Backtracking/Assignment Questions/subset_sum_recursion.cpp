#include <iostream>
using namespace std;

int subsetSumToKHelper(int input[], int n, int startIndex, int k)
{
    if (startIndex == n)
    {
        if (k == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int smallOutputSize1 = subsetSumToKHelper(input, n, startIndex + 1, k);
    int smallOutputSize2 = subsetSumToKHelper(input, n, startIndex + 1, k - input[startIndex]);

    return smallOutputSize1 + smallOutputSize2;
}

int subsetSumToK(int input[], int n, int k)
{
    return subsetSumToKHelper(input, n, 0, k);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int input[20], length, k;
        cin >> length;
        cin >> k;
        for (int i = 0; i < length; i++)
        {
            cin >> input[i];
        }
        int size = subsetSumToK(input, length, k);
        cout << size << endl;
    }
}