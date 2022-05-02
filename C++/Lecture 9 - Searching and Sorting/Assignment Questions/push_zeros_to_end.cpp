#include <iostream>
using namespace std;

void pushZeroesEnd(int *input, int size)
{
	int i = 0, j = size - 1, temp, non_zero = 0;
	for (i = 0; i < size; i++)
	{
		if (input[i] != 0)
		{
			temp = input[non_zero];
			input[non_zero] = input[i];
			input[i] = temp;
			non_zero++;
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

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}

		pushZeroesEnd(input, size);

		for (int i = 0; i < size; i++)
		{
			cout << input[i] << " ";
		}

		cout << endl;
		delete[] input;
	}

	return 0;
}