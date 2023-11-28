#include <iostream>
#include <stdlib.h>
#include <limits.h>
using namespace std;

int arr[40000][3] = {0};
int parent[40000] = {0};

void Union(int i, int j, int n)
{
	int temp, k, m;
	if(parent[i] > parent[j])
	{
		temp = parent[i];
		for(k = 0; k < n; k++)
		{
			if(parent[k] == temp)
			{
				parent[k] = parent[j];
			}
		}
	}else if(parent[j] > parent[i])
	{
		temp = parent[j];
		for(k = 0; k < n; k++)
		{
			if(parent[k] == temp)
			{
				parent[k] = parent[i];
			}
		}
	}
}

int Find(int i, int j){
	if(parent[i] != parent[j])
		return 1;
	else
		return 0;
}

int main(){
	int a, b, link, max = 0, i, j ,min = INT_MAX, cost = 0, step = 1;
	int n = -1;
	while(cin >> a >> b >> link)
	{
		arr[++n][0] = a;
		arr[n][1] = b;
		arr[n][2] = link;
		arr[++n][0] = b;
		arr[n][1] = a;
		arr[n][2] = INT_MAX;
		if(max < b)max = b;
	}
	cout << "Adjacency list:\n";
	for(i = 0; i <= max; i++)
	{
		cout << i << ": ";
		for(j = 0; j <= n; j++)
		{
			if(arr[j][0] == i)
			{
				cout << arr[j][1];
				cout << " -> ";
			}
		}
		cout << "end\n";
	}
	for(i = 0; i <= max; i++)
	{
		parent[i] = i;
	}
	int k;
	cout << "\nminimum spanning tree:\n";
	while(step <= max)
	{
		for(i = 0; i <= n; i++)
		{
			if(Find(arr[i][0],arr[i][1]))
			{
				if(arr[i][2] < min)
				{
					min = arr[i][2];
					k = i;
					a = arr[i][0];
					b = arr[i][1];
				}
			}
		}cout << step++ << ": <" << a << "," << b << ">\n";
		Union(a,b,max+1);
		arr[k][2] = INT_MAX;
		cost += min;
		min = INT_MAX;
	}
	cout << "\nThe cost of minimum spanning tree: " << cost << endl;
	return 0;
}

/*
0 1 28
0 5 10
1 2 16
1 6 14
2 3 12
3 4 22
3 6 18
4 5 25
4 6 24
->
Adjacency list:
0: 1 -> 5 -> end
1: 0 -> 2 -> 6 -> end
2: 1 -> 3 -> end
3: 2 -> 4 -> 6 -> end
4: 3 -> 5 -> 6 -> end
5: 0 -> 4 -> end
6: 1 -> 3 -> 4 -> end

minimum spanning tree:
1: <0,5>
2: <2,3>
3: <1,6>
4: <1,2>
5: <3,4>
6: <4,5>

The cost of minimum spanning tree: 99

0 1 88
0 2 58
0 4 10
1 2 82
1 3 92
2 4 67
3 4 7
->
Adjacency list:
0: 1 -> 2 -> 4 -> end
1: 0 -> 2 -> 3 -> end
2: 0 -> 1 -> 4 -> end
3: 1 -> 4 -> end
4: 0 -> 2 -> 3 -> end

minimum spanning tree:
1: <3,4>
2: <0,4>
3: <0,2>
4: <1,2>

The cost of minimum spanning tree: 157
*/
