#include <iostream>
using namespace std;

void heapify(int a[], int n, int i)
{
	int parent = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && a[left] > a[parent]) parent = left;
	if (right < n && a[right] > a[parent]) parent = right;

	if (parent != i)
	{
		a[parent] ^= a[i];
		a[i] ^= a[parent];
		a[parent] ^= a[i];

		heapify(a, n, parent);
	}
}

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

	for (int i = n / 2 - 1; i >= 0; i--) heapify(a, n, i);

	for (int i = n - 1; i > 0; i--)
	{
		a[0] ^= a[i];
		a[i] ^= a[0];
		a[0] ^= a[i];

		heapify(a, i, 0);
	}

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}