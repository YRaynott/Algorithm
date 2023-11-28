#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int c[20000][20000];

void LCS_length(char x[], char y[])
{
	int m = strlen(x), n = strlen(y), i, j;
	for(i = 0; i <= m; i++)
	{
		c[i][0] = 0;
	}
	for(j = 0; j <= n; j++)
	{
		c[0][j] = 0;
	}
	for(i = 1; i <= m; i++)
	{
		for(j = 1; j <= n; j++)
		{
			if(x[i] == y[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
			}
			else
			{
				c[i][j] = max(c[i-1][j], c[i][j-1]);
			}
		}
	}
	cout << c[m][n] << endl;
}

int main()
{
	char x[20000] = {0}, y[20000] = {0};
	cin >> x >> y;
	LCS_length(x,y);
	
	return 0;
}

/*
ABCBDAB
BDCABA
->4
*/
