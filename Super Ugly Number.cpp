#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int main()
{
	//n璶―材碭计;kΤ碭借计 
	int n, k, i, j;
	//aノㄓ借计 
	int a[1000] = {0};
	cin >> n >> k;
	//uglyノㄓsuper ugly number;tempノㄓ癘魁ヘ玡筁程Ω计 
	int ugly[n], temp[k];
	for(i = 0; i < k; i++)
	{
		cin >> a[i];
		temp[i] = 0;
	}
	for(i = 0; i < n; i++)
	{
		ugly[i] = INT_MAX;	//2147483647
	}
	ugly[0] = 1; 
	for(i = 1; i <= n; i++)
	{
		for(j = 0; j < k; j++)
		{
			ugly[i] = min(ugly[i], a[j]*ugly[temp[j]]);
		}
		//浪琩程沧琌ㄤtemp+1 
		for(j = 0; j < k; j++)
		{
			if(a[j]*ugly[temp[j]] == ugly[i])
			{
				temp[j]++;
			}
		}
	}
	cout << ugly[n-1] << endl;
	return 0;
}

/*
10 5
17 29 31 73 79
->841

20 5
7 11 41 43 97
->1681
*/
