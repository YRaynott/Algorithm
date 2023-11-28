#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_crossing(int A[], int low, int mid, int high){
	int cross_sum, max_left, max_right;
	int i, left_sum = INT_MIN, sum = 0;
	for(i = mid; i >= low; i--){
		sum += A[i];
		if(sum > left_sum){
			left_sum = sum;
			max_left = i;
		}
	}int right_sum = INT_MIN, j;
	sum = 0;
	for(j = mid+1; j <= high; j++){
		sum += A[j];
		if(sum > right_sum){
			right_sum = sum;
			max_right = j;
		}
	}return (left_sum + right_sum);
}

int find(int A[], int low, int high){
	int left_sum, right_sum, cross_sum;
	int mid;
	if(high == low){
		return A[low];
	}else{
		mid = (low + high)/2;
		left_sum = find(A,low,mid);
		right_sum = find(A,mid+1,high);
		cross_sum = max_crossing(A,low,mid,high);
	}if((left_sum >= right_sum) && (left_sum >= cross_sum)){
		return left_sum;
	}else if((right_sum >= left_sum) && (right_sum >= cross_sum)){
		return right_sum;
	}else{
		return cross_sum;
	}
}

int main(){
	int A[50000] = {0};
	int num, n = 0, sum = 0;
	while(scanf("%d",&num)!= EOF){
		A[++n] = num;
	}sum = find(A,1,n);
	printf("%d\n",sum);
	return 0;
}

/*
1 2 3 4 
10
10 -1 3 -12 11 -4 4 1 -10 6 
12
*/
