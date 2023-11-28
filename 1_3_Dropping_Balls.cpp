#include <iostream>
#include <limits.h>
using namespace std;

int main(){
	int n, i, num, d;
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> d >> num;
		int pos = 1, j = 1;
		while(j < d){
			if(num % 2 == 0){
				pos = pos*2+1;
			}else{
				pos *= 2;
			}
			if(num > 1){
				if(num % 2 == 0){
					num /= 2;
				}else{
					num = num/2+1;
				}
			}j++;
		}cout << pos << endl;
	}
	return 0;
}

/*
in:
5
4 2
3 4
10 1
2 2
8 128
-1
out:
12
7
512
3
255

in:
2
4 3
3 3
-1
out:
10
5
*/
