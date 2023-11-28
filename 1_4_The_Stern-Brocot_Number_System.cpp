#include <iostream>
#include <limits.h>
using namespace std;

int main(){
	//numerator¤À¤l¡Adenonminator¤À¥À 
	int num, deno;
	cin >> num >> deno;
	while((deno != 1 || num != 1)){
		int Ln = 0, Ld = 1, Mn = 1, Md = 1, Rn = 1, Rd = 0;
		long double Fd = num / (long double)deno;
		long double Mid = Mn / (long double)Md;
		while(!(num == Mn && deno == Md)){
			if(Fd > Mid){
				Ln = Mn;
				Ld = Md;
				Mn += Rn;
				Md += Rd;
				cout << "R";
			}else{
				Rn = Mn;
				Rd = Md;
				Mn += Ln;
				Md += Ld;
				cout << "L";
			}Mid = Mn / (long double)Md;
		}cout << "\n";
		cin >> num >> deno;
	}
	return 0;
}

/*
5 7
878 323
1 1
LRRL
RRLRRLRLLLLRLRRR

396 349
198 83
395 491
563 310
74 15
697 401
127 776
342 775
352 39
392 69
1 1
RLLLLLLLRRLLRLLLLL
RRLLRLRRLLLLL
LRRRRLLLLLLLLRLLRL
RLRRRRLLRRRLRLL
RRRRLRRRRRRRRRRRRR
RLRRLRRRRLRLLLLLLLL
LLLLLLRRRRRRRRRLLLLLLLLLLLLL
LLRRRLRRRLLLLLLLRR
RRRRRRRRRLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLLL
RRRRRLRRLLLLLLLRR
*/
