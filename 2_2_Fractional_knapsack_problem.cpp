#include <iostream>
#include <stdlib.h>
using namespace std;

struct item{
	int weight;
	int value;
};

int cmp(const void *a, const void *b)
{
	item *x = (item *)a;
	item *y = (item *)b;
	double ratio1 = (*x).value*1.0 / (*x).weight;
	double ratio2 = (*y).value*1.0 / (*y).weight;
	if(ratio1 < ratio2) return 1;
	else return -1;
}

int main()
{
	int n = -1;
	int capacity;
	cin >> capacity;
	item I[40000];
	while(cin >> I[++n].value)
	{
		cin >> I[n].weight;
	}qsort(I,n,sizeof(item),cmp);
	int load = 0, i = 0;
	double price = 0;
	while(load < capacity && i <= n)
	{
		if(I[i].weight <= capacity - load)
		{
			load += I[i].weight;
			price += I[i].value;
		}else
		{
			int remain = capacity - load;
			price += (remain * I[i].value * 1.0)/I[i].weight;
			load += remain;
		}
		i += 1;
	}
	printf("%.6lf\n",price);
	return 0;
}

/*
18
45 7
40 6
51 85
57 10
17 43
35 84
->113.500000

75
33 38
80 87
3 38
77 29
52 51
82 7
51 43
27 34
39 89
32 13
44 66
->221.837209
*/ 
