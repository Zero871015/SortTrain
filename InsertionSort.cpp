//TODO: Insertion sort

#include <iostream>
#include <fstream>
#include <time.h>
using namespace std;

//#define TEST_TIME

int main()
{
	ifstream fin("test.txt");
	int n;
	int *arr;
	fin >> n;
	arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
	}
	double t1,t2;
	t1 = clock();
	for (int i = 1; i < n; i++)
	{
#ifndef TEST_TIME
		if (i != 1)cout << endl;
#endif // !TEST_TIME

		int temp = arr[i];
		int j;
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > temp)
				arr[j + 1] = arr[j];
			else
			{
				break;
			}
		}
		arr[j + 1] = temp;
		for (int j = 0; j < n; j++)
		{
#ifndef TEST_TIME
			if (j != 0) cout << " ";
			cout << arr[j];
#endif // !TEST_TIME
		}
	}
	t2 = clock();
#ifdef TEST_TIME
	cout << (t2 - t1)/CLOCKS_PER_SEC;
#endif // TEST_TIME
	return 0;
}