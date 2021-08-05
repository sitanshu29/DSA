#include <bits/stdc++.h>   
using namespace std;
#define d 3

int maxGold(int g[][d] , int m, int n)
{
    int gold[m][n];
    for(int i = 0; i < m; i++)
    gold[i][n-1] = g[i][n-1];
    int w, x, y;
    for(int j = m-2; j >= 0; j--)
    {
    	for(int i = 0; i < n; i++)
    	{
    		w = gold[i][j+1];
			if (i-1 >= 0)
    		x = gold[i-1][j+1];
    		else
    		x = INT_MIN;
    		if (i+1 < n)
    		y = gold[i+1][j+1];
    		else
    		y = INT_MIN;
    		gold[i][j] = g[i][j] + max(x, max(y, w));
		}
	}
	int maxg = INT_MIN;
	for(int i = 0; i < m; i++)
	if (gold[i][0] > maxg)
	maxg = gold[i][0];
	return maxg;
}

int main()
{
    int mat[3][3] = {{1, 3, 3},
                   {2, 1, 4},
                  {0, 6, 4}};
    int m = 3, n = 3; 
    cout << maxGold(mat, m, n); 
    return 0; 
}