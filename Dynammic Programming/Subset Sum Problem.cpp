//Subset Sum Problem
#include <bits/stdc++.h>
using namespace std;
/* //Recursive
bool check(int arr[], int n, int sum)
{
    if(sum == 0)
    return true;
    if (n<=0)
    return false;
    if (sum < 0)
    return false;
    
    return (check(arr, n-1, sum) || check(arr, n-1, sum-arr[n-1]));
}*/
//Using DP
bool check(int arr[], int n, int sum)
{
    bool dp[n][sum+1];
    for(int i = 0; i < n ; i++)
    dp[i][0] = 1;
    for(int i = 1; i <= sum; i++)
    {
        if (i == arr[0])
        dp[0][i] = 1;
        else
        dp[0][i] = 0;
    }
    for(int i = 1; i < n; i++)
    for(int j = 1; j <= sum; j++)
    {
        if(arr[i] > j)
        dp[i][j] = dp[i-1][j];
        else
        {
            dp[i][j] = (dp[i-1][j] || dp[i-1][j-arr[i]]);
        }
    }
    for(int i = 0; i < n ; i++)
    {
        for(int j = 0; j <= sum; j++)
        cout << dp[i][j] << " ";
        cout << endl;
    }
    return dp[n-1][sum];
}

int main()
{
    int set[] = {2,3,5,7,10}; 
  int sum = 15; 
  int n = sizeof(set)/sizeof(set[0]); 
  if (check(set, n, sum) == true) 
     printf("Found a subset with given sum"); 
  else
     printf("No subset with given sum"); 
  return 0; 
}