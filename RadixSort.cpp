//TODO: Radix sort
//	Use too many STL function, very slow.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <time.h>
#include <fstream>
using namespace std;
//#define TEST_TIME

int main()
{
	ifstream fin("test.txt");
	double t1, t2;
	int n;
	int dig = 0;
	string *arr;
	fin >> n;
	arr = new string[n];
	for (int i = 0; i < n; i++)
	{
		fin >> arr[i];
		
	}
	t1 = clock();

	for (int i = 0; i < n; i++)
	{
		if (arr[i].length() > dig)dig = arr[i].length();
	}
	for (int i = 0; i < n; i++)
	{
		reverse(arr[i].begin(), arr[i].end());

		while (arr[i].length() < dig)
			arr[i].push_back('0');
	}
	for (int i = 0; i < dig; i++)
	{
#ifndef TEST_TIME
		if (i != 0)cout << endl;
#endif // !TEST_TIME

		vector<string> v[10];
		for (int j = 0; j < n; j++)
		{
			v[arr[j][i]-'0'].push_back(arr[j]);
		}
		int count = 0;
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < v[j].size(); k++)
			{
				arr[count] = v[j][k];
				count++;
			}
		}
		for (int j = 0; j < n; j++)
		{
#ifndef TEST_TIME
			if (j != 0)cout << " ";
#endif // !TEST_TIME
			string temp = arr[j];
			reverse(temp.begin(), temp.end());
#ifndef TEST_TIME
			cout << stoi(temp);
#endif // !TEST_TIME
		}
	}
	t2 = clock();
#ifdef TEST_TIME
	cout << (t2 - t1) / CLOCKS_PER_SEC;
#endif // TEST_TIME
	return 0;
}