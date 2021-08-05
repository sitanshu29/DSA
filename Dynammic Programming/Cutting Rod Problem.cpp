//Cutting Rod Problem
#include <bits/stdc++.h>
using namespace std;

int maxPrice(int prices[], int n)
{
    int dp[n+1][n+1];
    for(int i = 0; i < n+1; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++)
    for(int j = 1; j<= n; j++)
    {
        if (j < i)
        dp[i][j] = dp[i-1][j];
        else
		dp[i][j] = max(dp[i-1][j], prices[i-1]+ dp[i][j-i]);
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[n][n];
}

int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20}; 
    int size = sizeof(arr)/sizeof(arr[0]);
    int x = maxPrice(arr, size);
    cout << x;
    return 0;
}