#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	int a[n], b[n], x[m];
	int i, maxNum = 0, j;
	for(i = 0; i < n; i++)
		cin >> a[i];
	for(i = 0; i < n; i++)
	{
		cin >> b[i];
		maxNum = max(maxNum, b[i]);
	}
	for(i = 0; i < m; i++)
	{
		cin >> x[i];
	}
	int temp[maxNum+1]= {0};
	for(i = 0; i < n; i++)
	{
		for(j = a[i]; j < b[i]; j++)
		{
			temp[j]++;
		}
	}
	for(i = 1; i < maxNum+1; i++)
	{
		temp[i] += temp[i-1];
	}
	int result;
	for(i = 0; i < m-1; i++)
	{
		result = (x[i] <= maxNum) ? temp[x[i]-1] : temp[maxNum];
		cout << result << " ";
	}
	result = (x[i] <= maxNum) ? temp[x[i]-1] : temp[maxNum];
	cout << result << endl;
	return 0;
}
/*
3 3
3 2 1
6 8 10
7 2 12
->14 1 18
15 10
23 2 22 11 28 16 21 20 10 25 22 1 2 15 0 
50 8 29 34 56 17 41 43 18 52 45 23 31 34 25 
44 4 35 30 16 40 49 25 7 34 
->261 11 211 172 63 241 277 126 23 205
*/
