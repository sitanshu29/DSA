// Matrix Multiplication

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>


int minOp(int arr[], int n)
{
        int dp[n][n];

        for(int i = 1; i < n; i++)
        dp[i][i] = 0;

        for(int l = 2; l < n; l++)
        {
            for(int i = 1; i < n-l+1; i++)
            {
                int j = i+l-1;
                dp[i][j] = INT_MAX;
                int q;
                for(int k = i; k < j; k++)
                {
                    q = dp[i][k] + dp[k+1][j] + arr[i-1]*arr[k]*arr[j];
                    dp[i][j] = min(dp[i][j], q);
                }
            }
        }

        return dp[1][n-1] ;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    cin >> arr[i];

    cout << minOp(arr, n) << endl;   

    return 0;
}