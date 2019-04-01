//TODO: Quick sort

#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;
//#define TIME_TEST

void Partition(int *arr, int begin, int end, int &location)
{
	bool compareR = true;
	while (begin != end)
	{
		if (compareR)
		{
			for (; end > begin; end--)
			{
				if (arr[location] > arr[end])
				{
					compareR = false;
					int temp = arr[end];
					arr[end] = arr[location];
					arr[location] = temp;

					location = end;
					break;
				}
			}
		}
		else
		{
			for (; begin < end; begin++)
			{
				if (arr[location] < arr[begin])
				{
					compareR = true;
					int temp = arr[begin];
					arr[begin] = arr[location];
					arr[location] = temp;

					location = begin;
					break;
				}
			}
		}
	}
}

void Show(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i != 0)cout << " ";
		cout << arr[i];
	}
}

void QuickSort(int *arr, int begin, int end, int size,bool first)
{
	if (begin < end)
	{
		int location = begin;
		Partition(arr, begin, end, location);
#ifndef TEST_TIME
		if (!first)
			cout << endl;
		Show(arr, size);
#endif // !TEST_TIME
		QuickSort(arr, begin, location - 1, size, false);
		QuickSort(arr, location + 1, end, size, false);
	}
}

int main()
{
	ifstream fin("test.txt");
	double t1, t2;
	int n;
	int *arr;
	fin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
	t1 = clock();
	QuickSort(arr, 0, n - 1, n, true);
	t2 = clock();
#ifdef TEST_TIME
	cout << (t2 - t1) / CLOCKS_PER_SEC;
#endif // TEST_TIME
	return 0;
}