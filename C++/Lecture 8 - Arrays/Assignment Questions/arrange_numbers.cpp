#include <iostream>
using namespace std;

void arrange(int *arr, int n)
{
	int i, start = 1, end, j;
	if (n % 2 == 0)
	{
		j = 1;
		end = n;
	}
	else
	{
		j = 0;
		end = n - 1;
	}

}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int *arr = new int[n];
		arrange(arr, n);
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete[] arr;
	}
}