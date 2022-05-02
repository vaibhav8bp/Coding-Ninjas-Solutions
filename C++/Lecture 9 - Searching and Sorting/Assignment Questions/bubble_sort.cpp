#include <iostream>
using namespace std;

void bubbleSort(int *input, int size)
{
	int i, j, swap, temp;
	for (i = 0; i < size - 1; i++)
	{
		swap = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (input[j] > input[j + 1])
			{
				temp = input[j];
				input[j] = input[j + 1];
				input[j + 1] = temp;
				swap++;
			}
		}
		if (swap == 0)
		{
			break;
		}
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

		for (int i = 0; i < size; ++i)
		{
			cin >> input[i];
		}

		bubbleSort(input, size);

		for (int i = 0; i < size; ++i)
		{
			cout << input[i] << " ";
		}

		delete[] input;
		cout << endl;
	}
}