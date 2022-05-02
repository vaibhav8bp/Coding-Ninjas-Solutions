#include <iostream>
using namespace std;

void sumOfTwoArrays(int *input1, int size1, int *input2, int size2, int *output)
{
	int i, n, sum, carry = 0, a, b, position = 1;
	n = (size1 >= size2) ? size1 : size2; //last index of storing array not size
	for (i = n; i >= 0;)
	{
		a = (size1 - position < 0) ? 0 : input1[size1 - position];
		b = (size2 - position < 0) ? 0 : input2[size2 - position];
		sum = a + b + carry;
		(sum <= 9) ? (output[i--] = sum, carry = 0) : (output[i--] = (sum % 10), carry = 1);
		if (i == 0)
		{
			output[i] = carry;
			break;
		}
		position++;
	}
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int size1;
		cin >> size1;

		int *input1 = new int[size1];

		for (int i = 0; i < size1; ++i)
		{
			cin >> input1[i];
		}

		int size2;
		cin >> size2;

		int *input2 = new int[size2];

		for (int i = 0; i < size2; ++i)
		{
			cin >> input2[i];
		}

		int outsize = 1 + max(size1, size2);

		int *output = new int[outsize];

		sumOfTwoArrays(input1, size1, input2, size2, output);

		for (int i = 0; i < outsize; ++i)
		{
			cout << output[i] << " ";
		}

		delete[] input1;
		delete[] input2;
		delete[] output;
		cout << endl;
	}

	return 0;
}