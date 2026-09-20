#include <iostream>
using namespace std;

int main()
{
	int a[20];
	int n, i = 0;

	cin >> n;
	do
	{
		cin >> a[i];
		i++;
	} while (i < n);

	for (int i = 0; i < n - 1; i++)
	{
		bool swapped = false;

		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
			{
				a[j] = a[j] ^ a[j + 1];
				a[j + 1] = a[j] ^ a[j + 1];
				a[j] = a[j] ^ a[j + 1];

				swapped = true;
			}
		if (!swapped)
			break;
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	return 0;
}