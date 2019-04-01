//TODO: Generate random data

#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int i = 1; i <= n; i++)
		{
			arr[i - 1] = i;
		}
		srand(clock());
		for (int i = 0; i < n; i++)
		{
			int r = rand() % n;
			int temp = arr[i];
			arr[i] = arr[r];
			arr[r] = temp;
		}

		cout << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << endl;
	}

	return 0;
}