#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int a[n*n];
	int i;
	for(i = 0; i < n*n; i++)
	{
		cin >> a[i];
	}
	sort(a, a+(n*n));
	cout << a[k-1] << endl;
	return 0;
}
/*
3 6 69 152 193 146 190 230 149 275 368
->193
2 3 80 124 103 130
->124
*/
