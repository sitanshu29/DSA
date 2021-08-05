//Partition Problem
#include <bits/stdc++.h>
using namespace std;
/* //Recursive Approach
bool Utility(int arr[], int index, int n, int curr, int half)
{
    if (index >= n || curr > half)
    return false;
    if (curr == half)
    return true;
    return (Utility(arr, index+1, n, curr+arr[index], half)|| Utility(arr, index+1, n, curr, half));
}

bool partition(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    sum+= arr[i];
    if (sum % 2 != 0)
    return false;
    return Utility(arr, 0, n,0, sum/2);
}
*/

bool partition(int arr[], int n)
{
    int sum = 0;
    for(int i = 0; i < n; i++)
    sum+= arr[i];
    if (sum%2 == 1)
    //return false;
    cout <<"Not possible\n";

    bool dp[n][(sum/2)+1];
    for(int i = 0; i <= n; i++)
    dp[i][0] = 1;
    for(int i = 1; i <= sum/2; i++)
    {
        if (arr[0] == i)
        dp[0][i] = 1;
        else
        dp[0][i] = 1;
    }

    for(int i = 1; i < n; i++)
    for(int j = 1; j <= sum/2; j++)
    {
        if (j < arr[i])
        dp[i][j] = dp[i-1][j];
        else
        dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i]];
    }
    if (dp[n-1][sum/2] == 0)
    //return false;
    cout << "Not possible\n";
    while(j != 0)
    {
        if (dp[i][j] == dp[i-1][j])
        i = i-1;
        else
        {
            cout << arr[i] << " ";
            i = i-1;
            j = j-arr[i];
        }
    }
    //return true;
    cout << "\npossible\n";
}
int main()
{
    int arr[] = {3, 1, 5, 9, 12};  
    int n = sizeof(arr)/sizeof(arr[0]);  
   /* if (partition(arr, n) == true)  
        cout << "Can be divided into two subsets "
                "of equal sum";  
    else
        cout << "Can not be divided into two subsets"
                " of equal sum"; */
    partition(arr, n);
    return 0;  
}