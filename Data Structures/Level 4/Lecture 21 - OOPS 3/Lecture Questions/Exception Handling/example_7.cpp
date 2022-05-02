#include <climits>
#include <vector>
int solve2(string s, string v, string ans, vector<vector<int>> &vec)
{

    // if(v.size()==0)return ans.size()+1;

    if (s.size() == 0)
        return 1095;
    if (vec[s.size()][v.size()] != -1)
        return vec[s.size()][v.size()];
    int a = solve2(s.substr(1), v, ans, vec);

    char x = s[0];
    int k = -1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == x)
        {
            k = i;
            break;
        }
    }

    if (k == -1)
    {

        return 1;
    }

    int b = solve2(s.substr(1), v.substr(k + 1), ans + x, vec) + 1;

    return vec[s.size()][v.size()] = min(b, a);
}

int solve(string s, string v)
{

    vector<vector<int>> vec(s.size() + 1, vector<int>(v.size() + 1, -1));
    return solve2(s, v, "", vec);
}