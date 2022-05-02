#include <iostream>
using namespace std;

int lcs_helper(string s, string t, int **output)
{
    // Base Case
    if (s.empty() || t.empty())
    {
        return 0;
    }
    // Check if answer already exits
    if (output[s.length()][t.length()] != -1)
    {
        return output[s.length()][t.length()];
    }
    // Recursive Calls
    int ans;
    if (s[0] == t[0])
    {
        ans = 1 + lcs_helper(s.substr(1), t.substr(1), output);
    }
    else
    {
        int a = lcs_helper(s.substr(1), t, output);
        int b = lcs_helper(s, t.substr(1), output);
        int c = lcs_helper(s.substr(1), t.substr(1), output);
        ans = max(a, max(b, c));
    }
    output[s.length()][t.length()] = ans;
    return ans;
}

int lcs(string s, string t)
{

    int m = s.length();
    int n = t.length();
    int **output = new int *[m + 1];
    for (int i = 0; i <= m; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            output[i][j] = -1;
        }
    }
    return lcs_helper(s, t, output);
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << lcs(s, t) << endl;
    return 0;
}