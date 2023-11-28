#include <iostream>
using namespace std;

int main(){
	int n, i;
	cin >> n;
	int num[n], d[n];
	for(i = 0; i < n; i++)
	{
		cin >> num[i];
		d[i] = num[0];
	}
	int t = 1;
	for(i = 1; i < n; i++)
	{
		if(num[i] > d[t-1])
		{
			d[t] = num[i];
			t++;
		}
		else
		{
			int right = t-1, left = 0, mid = 0;
			while(right > left)
			{
				mid = left + (right - left)/2;
				if(d[mid] >= num[i]) right = mid;
				else left = mid + 1;
			}
			d[right] = num[i];
		}
	}
	cout << t << endl;
	return 0;
}

/*
10
6 7 3 7 10 8 6 1 8 10
->4

20
3 11 16 1 18 7 5 12 20 10 16 3 3 3 5 4 20 14 5 4
->5
*/
