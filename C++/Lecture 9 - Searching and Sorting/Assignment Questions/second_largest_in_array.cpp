#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int *input, int n)
{
	int max = INT_MIN, smax = INT_MIN, i;
	for (i = 0; i < n; i++)
	{
		if (max < input[i])
		{
			smax = max;
			max = input[i];
		}
		else if (smax < input[i] && input[i] < max)
		{
			smax = input[i];
		}
	}
	return smax;
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

		cout << findSecondLargest(input, size) << endl;

		delete[] input;
	}

	return 0;
}