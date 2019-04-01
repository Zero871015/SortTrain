//TODO: Merge sort

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;
//#define TEST_TIME

void Merge(int *arr, int begin, int mid, int end, int size)
{
	if (end - begin + 1 == 2)
	{
		for (int i = 0; i < 2; i++)
		{
#ifndef TIME_TEST
			cout << arr[begin + i] << endl;
#endif // !TIME_TEST

		}
	}
	int *temp = new int[end - begin + 1];
	int i = begin, j = mid + 1;
	for (int index = 0; index < end - begin + 1; index++)
	{
		if (i > mid)
		{
			temp[index] = arr[j];
			j++;
		}
		else if (j > end)
		{
			temp[index] = arr[i];
			i++;
		}
		else if (arr[i] > arr[j])
		{
			temp[index] = arr[j];
			j++;
		}
		else
		{
			temp[index] = arr[i];
			i++;
		}
	}
	for (int i = 0; i < end - begin + 1; i++)
	{
#ifndef TEST_TIME
		if (i != 0)cout << " ";
		cout << arr[begin + i];
#endif // !TEST_TIME

		arr[begin + i] = temp[i];
	}
#ifndef TEST_TIME
	if (size != end - begin + 1)
		cout << endl;
#endif // !TEST_TIME
	
}

void MergeSort(int *arr, int begin, int end, int size)
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;
		MergeSort(arr, begin, mid, size);
		MergeSort(arr, mid + 1, end, size);
		Merge(arr, begin, mid, end, size);
	}
}

int main()
{
	double t1, t2;
	ifstream fin("test.txt");
	int n;
	int *arr;
	fin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
	t1 = clock();
	MergeSort(arr, 0, n - 1, n);
	t2 = clock();
#ifdef TEST_TIME
	cout << (t2 - t1) / CLOCKS_PER_SEC;
#endif // TEST_TIME
	return 0;
}