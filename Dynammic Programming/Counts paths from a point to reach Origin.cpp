//Counts paths from a point to reach Origin (Take either left or down steps)
#include <bits/stdc++.h>
using namespace std;
/* //Recursive
int paths(int m, int n)
{
	if (m == 0 && n == 0)
	return 0;
	if (m == 0 || n == 0)
	return 1;
	else
	return paths(m-1, n) + paths(m, n-1);
}
*/

int paths(int m, n)
{
    int arr[m+1][n+1];
    arr[0][0] = 0;
    for(int i = 1; i <= m; i++)
    arr[i][0] = 1;
    for(int i = 1; i<=n; i++)
    arr[0][i] = 1;
    for(int i = 1; i <= m; i++)
    for(int j = 1; j <= n; j++)
    {
        arr[i][j] = arr[i-1][j] + arr[i][j-1];
    }
    return arr[m][n];
}
int main()
{
	int m ,n;
	cin >> m >> n;
	cout << paths(m, n) << endl;
	return 0;
}
