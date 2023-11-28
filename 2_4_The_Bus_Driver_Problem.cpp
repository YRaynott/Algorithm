#include <iostream>
#include <algorithm>	//sort
using namespace std;

int main(){
	int n, d, r, i;
	while(cin >> n >> d >> r){
		if(n == 0 && d == 0 && r == 0)
			break;
		else
		{
			int mor[100] = {0}, eve[100] = {0};
			for(i = 0; i < n; i++)
			{
				cin >> mor[i];
			}sort(mor, mor + n);
			for(i = 0; i < n; i++)
			{
				cin >> eve[i];
			}sort(eve, eve + n);
			int sum = 0;
			for(i = 0; i < n; i++)
			{
				if(mor[i] + eve[n-i-1] > d)
				{
					sum += (mor[i] + eve[n-i-1] - d)*r;
				}
			}
			cout << sum << endl;
		}
	}
	return 0;
}

/*
2 20 5
10 15 
10 15 
2 20 5
10 10 
10 10 
0 0 0
->
50
0

4 6 4
1 1 16 15 
7 10 10 12 
1 19 1
19 
5 
2 14 5
19 11 
8 10 
0 0 0
->
192
5
100
*/
