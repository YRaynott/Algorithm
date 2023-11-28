#include <iostream>
#include <limits.h>
#include <algorithm>
using namespace std;

int minSubArrayLen(int n, int s, int num[]){
	int left = 0, right = 0, minlen = INT_MAX;
	int sum = num[0];
	while(right < n){
		while(sum < s && right < n){
			right++;
			sum += num[right];
		}
		if(sum >= s)
		{
			minlen = min(minlen,right - left + 1);
			sum -= num[left];
			left++;
		}
	}return minlen > n ? 0 : minlen;
}

int main(){
	int n, s, i;
	cin >> n >> s;
	int num[n] = {0};
	for(i = 0; i < n; i++){
		cin >> num[i];
	}cout << minSubArrayLen(n,s,num) << endl;
	return 0;
}

/*
10 348 48 99 78 52 21 39 67 83 80 38
->6
10 610 48 99 78 52 21 39 67 83 80 38
->0 
*/
