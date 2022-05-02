#include <iostream>
using namespace std;

int solveHelper(string s, string v, int **output)
{
    if (s.empty())
    {
        return 1095;
    }
    if (v.empty())
    {
        return 1;
    }
    if (output[s.length()][v.length()] != -1)
    {
        return output[s.length()][v.length()];
    }
    int k = 0;
    while (v[k] != '\0')
    {
        if (v[k] == s[0])
        {
            break;
        }
        k++;
    }
    // a character present in s is not present in v therefore it is the answer itself
    if (k == v.length())
    {
        return 1;
    }
    int exclude = solveHelper(s.substr(1), v,output);
    int include = 1 + solveHelper(s.substr(1), v.substr(k + 1),output);
    output[s.length()][v.length()] = min(include, exclude);
    return min(include, exclude);
}

int solve(string s, string v)
{
    int m = s.length();
    int n = v.length();
    int **output = new int *[m + 1];
    for (int i = 0; i < m + 1; i++)
    {
        output[i] = new int[n + 1];
    }
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            output[i][j] = -1;
        }
    }
    return solveHelper(s, v, output);
}

int main()
{
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}