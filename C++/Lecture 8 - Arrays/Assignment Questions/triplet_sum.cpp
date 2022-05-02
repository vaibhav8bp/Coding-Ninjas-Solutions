#include <iostream>
using namespace std;

int tripletSum(int *input, int size, int x)
{
	int i, j, k, count = 0;
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			for (k = j + 1; k < size; k++)
			{
				if (input[i] + input[j] + input[k] == x)
				{
					count++;
				}
			}
		}
	}
	return count;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size;
		int x;
		cin >> size;

		int *input = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> input[i];
		}
		cin >> x;

		cout << tripletSum(input, size, x) << endl;

		delete[] input;
	}

	return 0;
}