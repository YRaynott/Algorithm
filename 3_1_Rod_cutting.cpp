#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int r[50000] = {0};

void bottom_up_cut_rod(int p[], int n)
{
	int i, j, q;
	r[0] = 0;
	for(j = 1; j <= n; j++)
	{
		q = INT_MIN;
		for(i = 1; i <= j; i++)
		{
			q = max(q,p[i] + r[j-i]);
		}
		r[j] = q;
	}
}

int main(){
	int rod, i;
	int price[50000] = {0};
	cin >> rod;
	while(cin >> i){
		cin >> price[i];
		if(i == 0)
			break;
	}
	bottom_up_cut_rod(price,rod);
	cout << r[rod] << endl;
	return 0;
}

/*
長度 價格 
4
1 1
2 5
3 8
4 9
5 10
6 17
7 17
8 20
9 24
10 30
0 0
->10

16
1 1
2 5
3 8
4 9
5 10
6 17
7 17
8 20
9 24
10 30
11 40
12 26
0 0
->53
*/
