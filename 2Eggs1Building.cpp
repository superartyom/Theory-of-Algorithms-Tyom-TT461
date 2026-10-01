#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int drops = 0;
	int sum = 0;

	while (sum < n)
	{
		drops++;
		sum += drops;
	}

	cout << drops;
	return 0;
}