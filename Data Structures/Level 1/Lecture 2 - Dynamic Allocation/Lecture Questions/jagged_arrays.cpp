#include <iostream>
using namespace std;

int main()
{
    int m, i, j;
    cin >> m;
    int **p = new int *[m];
    for (i = 0; i < m; i++)
    {
        p[i] = new int[i + 1];
        for (j = 0; j < i + 1; j++)
        {
            cin >> p[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < i + 1; j++)
        {
            cout << p[i][j] << " ";
        }
        cout << endl;
    }

    for (i = 0; i < m; i++)
    {
        delete[] p[i];
    }
    delete[] p;
    return 0;
}