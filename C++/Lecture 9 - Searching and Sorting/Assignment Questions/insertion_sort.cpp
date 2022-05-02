#include <iostream>
using namespace std;

void insertionSort(int *input, int size)
{
	int i, j, check;
	for (i = 1; i < size; i++)
	{
		check = input[i];
		j = i - 1;
		while (j >= 0 && input[j] > check)
		{
			input[j + 1] = input[j];
			j--;
		}
		input[j + 1] = check;
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
		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		insertionSort(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}

	return 0;
}