#include <iostream>
#include <algorithm>
using namespace std;

int search(long long int s[], long long int t[], int i, int n)
{
	long long int left = i, right = n-1;
	if(i == 0)
	{
		if(t[right] < s[i]) return -1;
		else
		{
			while(left <= right)
			{
				int mid = (left + right)/2;
				if((t[mid]) < s[i])
				{
					left = mid + 1;
				}
				else
				{
					right = mid - 1;
				}
			}
		return left+1;
		}
	}
	else if((t[right]-t[i-1]) < s[i]) return -1;
	else
	{
		while(left <= right)
		{
			int mid = (left + right)/2;
			if((t[mid]-t[i-1]) < s[i])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		return left+1;
	}
}

int main(){
	int n, i;
	cin >> n;
	long long int s[n] = {0}, t[n] = {0};
	s[0] = t[0] = 0;
	for(i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	cin >> t[0];
	for(i = 1; i < n; i++)
	{
		cin >> t[i];
		if(t[i] == s[i]) s[i] = 0;
		t[i] += t[i-1];
	}
	for(i = 0; i < n; i++)
	{
		if(s[i] == 0) cout << i+1 << " ";
		else cout << search(s,t,i,n) << " ";
	}cout << endl;
	return 0;
}

/*
5
20 5 7 9 1
3 6 4 5 1
->-1 2 4 -1 5 
6
7 11 5 13 18 2
5 1 9 8 1 4
->3 4 3 6 -1 6 
2
0 1000000000
0 1000000000
->1 2 
5
0 0 5 0 0
0 0 5 0 0
->1 2 3 4 5 
*/
