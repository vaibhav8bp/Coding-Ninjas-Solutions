#include <iostream>
using namespace std;

int lcs(string s, string t)
{
    int m = s.length();
    int n = t.length();
    int **answer = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        answer[i] = new int[n + 1];
    }
    for (int i = 0; i < n + 1; i++)
    {
        answer[0][i] = 0;
    }
    for (int i = 0; i < m + 1; i++)
    {
        answer[i][0] = 0;
    }
    for (int i = 1; i < m + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (s[m - i] == t[n - j])
            {
                answer[i][j] = 1 + answer[i - 1][j - 1];
            }
            else
            {
                answer[i][j] = max(answer[i][j - 1], max(answer[i - 1][j - 1], answer[i - 1][j]));
            }
        }
    }
    return answer[m][n];
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
    return 0;
    return 0;
}