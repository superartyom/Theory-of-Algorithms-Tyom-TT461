#include <iostream>
using namespace std;
 
int main() {
	int a[20];
	int n, i = 0;
	cin >> n;
	do
	{
		cin >> a[i];
		i++;
	} while (i < n);
 
	for (int i = 1; i < n; i++)
	{
		int k = a[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (k <= a[j])
				a[j+1] = a[j];
			else
				break;
			a[j] = k;
		}
	}
 
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return 0;
}
