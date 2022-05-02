#include <iostream>
using namespace std;

int binarySearch(int *input, int n, int val)
{
	int low = 0, end = n - 1, mid;
	while (low <= end)
	{
		mid = (low + end) / 2;
		if (input[mid] == val)
		{
			return mid;
		}
		else if (input[mid] < val)
		{
			low = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return -1;
}

int main()
{

	int size;
	cin >> size;
	int *input = new int[size];

	for (int i = 0; i < size; ++i)
	{
		cin >> input[i];
	}

	int t;
	cin >> t;

	while (t--)
	{
		int val;
		cin >> val;
		cout << binarySearch(input, size, val) << endl;
	}

	delete[] input;
	return 0;
}