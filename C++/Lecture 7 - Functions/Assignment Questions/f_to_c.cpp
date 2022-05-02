#include <iostream>
using namespace std;

void printTable(int start, int end, int step)
{
    if (start <= end)
    {
        int celsius = (5.0 / 9) * (start - 32);
        cout << start << " " << celsius << endl;
        start += step;
        printTable(start, end, step);
    }
}

int main()
{
    int start, end, step;
    cin >> start >> end >> step;
    printTable(start, end, step);
    return 0;
}