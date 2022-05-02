#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m)
{
    unordered_map<int, int> intersection;
    for (int i = 0; i < m; i++)
    {
        intersection[arr2[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (intersection[arr1[i]] > 0)
        {
            cout << arr1[i] << endl;
            intersection[arr1[i]]--;
        }
    }
}

int main()
{
    int n;
    cin >> n;

    int *arr1 = new int[n];

    for (int i = 0; i < n; ++i)
    {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    int *arr2 = new int[m];

    for (int i = 0; i < m; ++i)
    {
        cin >> arr2[i];
    }

    printIntersection(arr1, arr2, n, m);

    delete[] arr1;
    delete[] arr2;
}