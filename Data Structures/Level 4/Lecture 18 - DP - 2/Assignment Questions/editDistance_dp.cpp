#include <iostream>
#include <cstring>
using namespace std;

int editDistance(string s1, string s2)
{
    if (s1.empty())
    {
        return s2.length();
    }
    else if (s2.empty())
    {
        return s1.length();
    }
    int m = s1.length();
    int n = s2.length();
    int **output = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        output[0][i] = i;
    }
    for (int i = 1; i < m + 1; i++)
    {
        output[i][0] = i;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s1[m - i] == s2[n - j])
            {
                output[i][j] = output[i - 1][j - 1];
            }
            else
            {
                int a = output[i][j - 1];
                int b = output[i - 1][j];
                int c = output[i - 1][j - 1];
                output[i][j] = min(a, min(b, c)) + 1;
            }
        }
    }
    return output[m][n];
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}