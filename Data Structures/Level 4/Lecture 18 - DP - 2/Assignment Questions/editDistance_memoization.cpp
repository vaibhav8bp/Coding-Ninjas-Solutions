#include <iostream>
#include <cstring>
using namespace std;

int editDistanceHelper(string s1, string s2, int **output)
{
    if (s1.empty())
    {
        return s2.length();
    }
    else if (s2.empty())
    {
        return s1.length();
    }
    else if (s1 == s2)
    {
        return 0;
    }

    if (s1[0] == s2[0])
    {
        return editDistanceHelper(s1.substr(1), s2.substr(1), output);
    }

    if (output[s1.length()][s2.length()] != -1)
    {
        return output[s1.length()][s2.length()];
    }

    int a = editDistanceHelper(s1.substr(1), s2, output);
    int b = editDistanceHelper(s1, s2.substr(1), output);
    int c = editDistanceHelper(s1.substr(1), s2.substr(1), output);
    int answer = min(a, min(b, c)) + 1;
    output[s1.length()][s2.length()] = answer;
    return answer;
}

int editDistance(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
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
    return editDistanceHelper(s1, s2, output);
}

int main()
{
    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    cout << editDistance(s1, s2) << endl;
}