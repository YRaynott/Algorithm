#include <iostream>
using namespace std;

int main(){
	int a[30000], s[30000], f[30000] = {0};
	int n, k = 0;
	while(cin >> n)
	{
		a[++k] = n;
		cin >> s[n] >> f[n];
	}
	int i = 1, m, A[30000] = {0};
	k = 0;
	A[++k] = a[1];
	for(m = 2; m <= n; m++)
	{
		if(s[m] >= f[i]){
			A[++k] = a[m];
			i = m;
		}
	}
	for(i = 1; i <= k; i++){
		cout << A[i] << " ";
	}cout << endl;
	return 0;
}

/*
1 2 3
2 0 7
3 3 8
4 3 8
5 6 11
6 4 13
7 4 13
8 5 14
9 10 20
10 10 21
->1 3 9 

1 0 5
2 3 8
3 6 8
4 1 9
5 9 10
6 2 10
7 10 11
8 6 11
9 0 11
10 4 12
11 10 13
12 5 14
13 7 15
14 4 15
15 6 15
16 10 16
17 11 17
18 7 17
19 9 18
20 11 22
->1 3 5 7 17 
*/
