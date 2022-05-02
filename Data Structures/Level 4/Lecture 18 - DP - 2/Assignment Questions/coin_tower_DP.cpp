#include <iostream>
#include <string>
using namespace std;

string findWinner(int n, int x, int y)
{
    int atmost = max(1, max(x, y));
    bool *output = new bool[n + 1];
    for (int i = 1; i <= atmost; i++)
    {
        output[i] = true;
    }
    for (int i = atmost + 1; i < n + 1; i++)
    {
        bool taking1Step = output[i - 1];
        bool takingXStep = output[i - x];
        bool takingYStep = output[i - y];
        output[i] = !(taking1Step && takingXStep && takingYStep);
    }
    if (output[n])
    {
        return "Beerus";
    }
    else
    {
        return "Whis";
    }
}

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    cout << findWinner(n, x, y);
}