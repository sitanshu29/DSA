//Given a value N, if we want to make change for N cents, and we have infinite supply of 
//each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change?
#include <bits/stdc++.h>
using namespace std;
/*      Recursive Solution
int ways(int arr[], int m, int n)   //m : size of array  , n : Amount
{
    if (n == 0)
    return 1;
    if (n < 0)
    return 0;

    if (m <= 0 && n >= 1)
    return 0;

    return ways(arr, m-1, n) + ways(arr, m, n-arr[m-1]);

}*/

//Using Dynammic Programming
int ways(int coin[], int m, int n)
{
    int arr[m][n+1];
    for(int i = 0; i < m; i++)
    arr[i][0] = 1;

    for(int i = 1; i <= n; i++)
    {
        if (i % coin[0] == 0)
        arr[0][i] = 1;
        else
        arr[0][i] = 0;
    }

    for(int i = 1; i < m; i++)
    for(int j = 1; j <= n; j++)
    {
        if (coin[i] > j)
        arr[i][j] = arr[i-1][j];
        else
        {
            arr[i][j] = arr[i-1][j] + arr[i][j-coin[i]];
        }
    }
    return arr[m-1][n];

}

int main()
{
    int arr[] = {2,3,5,10}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 15; 
    cout << ways(arr, m, n); 
    return 0; 
}