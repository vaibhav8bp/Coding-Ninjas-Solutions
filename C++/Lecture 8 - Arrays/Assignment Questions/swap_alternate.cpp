#include <iostream>
using namespace std;

void swapAlternate(int *arr, int size)
{
	int i, q, temp;
	if (size % 2 == 0)
	{
		q = size;
	}
	else
	{
		q = size - 1;
	}
	for (i = 0; i < q; i += 2)
	{
		temp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = temp;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		int *arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		swapAlternate(arr, size);
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		delete[] arr;
	}
}