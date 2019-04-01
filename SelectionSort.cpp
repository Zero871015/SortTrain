//TODO: Selection sort

#include <iostream>
using namespace std;

void SelectionSort(int arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[j] < arr[min])min = j;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	SelectionSort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}