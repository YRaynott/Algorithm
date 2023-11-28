#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int A[], int p, int q, int r){
	int L[30000] = {0}, R[30000] = {0};
	int i, j, n1, n2, k;
	n1 = q-p+1;
	n2 = r-q;
	for(i = 1; i <= n1; i++){
		L[i] = A[p+i-1];
	}for(j = 1; j <= n2; j++){
		R[j] = A[q+j];
	}L[n1+1] = R[n2+1] = INT_MAX;
	i = j = 1;
	for(k = p; k <= r; k++){
		if(L[i] <= R[j]){
			A[k] = L[i++];
		}else{
			A[k] = R[j++];
		}
	}
}

void merge_sort(int A[], int p, int r){
	int q;
	if(p < r){
		q = (p+r)/2;
		merge_sort(A,p,q);
		merge_sort(A,q+1,r);
		merge(A,p,q,r);
	}
}

int main(){
	int A[50000] = {0};
	int num, r = 0;
	while(scanf("%d",&num)!=EOF){
		A[++r] = num;
	}merge_sort(A,1,r);
	int i;
	for(i = 1; i <= r; i++){
		printf("%d ",A[i]);
	}printf("\n");
	return 0;
}
/*
4 8 0 3 2 
*/
