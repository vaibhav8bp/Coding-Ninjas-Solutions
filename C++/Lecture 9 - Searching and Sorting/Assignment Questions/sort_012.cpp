#include <iostream>
using namespace std;

void sort012(int *arr, int n)
{
	int i = 0, next_zero = 0, next_two = n - 1, temp;
	while (i <= next_two)
	{
		if (arr[i] == 0)
		{
			temp = arr[next_zero];
			arr[next_zero] = arr[i];
			arr[i] = temp;
			next_zero++;
		}
		else if (arr[i] == 2)
		{
			temp = arr[next_two];
			arr[next_two] = arr[i];
			arr[i] = temp;
			next_two--;
			i--;
		}
		i++;
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

		sort012(arr, size);

		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}

		delete[] arr;
		cout << endl;
	}

	return 0;
}