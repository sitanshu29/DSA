#include <bits/stdc++.h>    //Need to revis
using namespace std;
/* //Printing all the increasing subsequences recursively
void print(vector<int> lis)
{
    for(int i = 0; i < lis.size(); i++)
    cout << lis[i] << " ";
    cout << endl;
}

void _LIS(int arr[], int i, int n, vector<int> lis)
{
    if (i >= n)
    {
        print(lis);
        return;
    }
    if (arr[i] > lis[lis.size()-1])
    {#include <bits/stdc++.h>
using namespace std;
/* //Printing all the increasing subsequences recursively
void print(vector<int> lis)
{
    for(int i = 0; i < lis.size(); i++)
    cout << lis[i] << " ";
    cout << endl;
}

void _LIS(int arr[], int i, int n, vector<int> lis)
{
    if (i >= n)
    {
        print(lis);
        return;
    }
    if (arr[i] > lis[lis.size()-1])
    {
        lis.push_back(arr[i]);
        _LIS(arr, i+1, n, lis);
        lis.pop_back();
        _LIS(arr, i+1, n, lis);
    }
    else
    _LIS(arr, i+1, n, lis);
}

void LIS(int arr[], int n)
{
    vector<int> lis;
    for(int i = 0; i < n; i++)
    {
        lis.push_back(arr[i]);
        _LIS(arr, i+1, n, lis);
        lis.pop_back();
    }
}*/
//Printing LIS using LCS algorithm
/*int LIS(int arr[], int n)
{
    int temp[] = arr;
    sort(temp, temp+n);
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i = 1; i <=n; i++)
    for(int j = 1; j <= n; j++)
    {
        if (arr[i] == arr[j])
        dp[i][j] = dp[i-1][j-1];
        else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    return dp[n][n];
}*/

//Printing LIS using DP but not LCS algorithm
int LISDP(int arr[], int n)
{
    int lis[n];
    int subseq[n];
    lis[0] = 1;
    subseq[0] = -1;
    for(int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[j]+1 > lis[i])
            {
                lis[i] = lis[j]+1;
                subseq[i] = j;
            }
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++)
    if (lis[i] > lis[max])
    max = i;
    int temp = max;
    stack<int> st;
    while(subseq[temp] != -1)
    {
        st.push(arr[temp]);
        temp = subseq[temp];
        
    }
    for(int i = 0; i < n; i++)
    cout << lis[i] << " ";
    cout << endl;
    for(int i = 0; i < n; i++)
    cout << subseq[i] << " ";
    cout << endl;
    
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return lis[max];

}

int main()
{
    int arr[] = { 4,1,12,2,10,6,9,13,3,11,7,15}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << LISDP(arr, n); 
    return 0;
}


        lis.push_back(arr[i]);
        _LIS(arr, i+1, n, lis);
        lis.pop_back();
        _LIS(arr, i+1, n, lis);
    }
    else
    _LIS(arr, i+1, n, lis);
}

void LIS(int arr[], int n)
{
    vector<int> lis;
    for(int i = 0; i < n; i++)
    {
        lis.push_back(arr[i]);
        _LIS(arr, i+1, n, lis);
        lis.pop_back();
    }
}*/
//Printing LIS using LCS algorithm
int LIS(int arr[], int n)
{
    int temp[] = arr;
    sort(temp, temp+n);
    int dp[n+1][n+1];
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
        dp[0][i] = 0;
    }
    for(int i = 1; i <=n; i++)
    for(int j = 1; j <= n; j++)
    {
        if (arr[i] == arr[j])
        dp[i][j] = dp[i-1][j-1];
        else
        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    }
    return dp[n][n];
}

//Printing LIS using DP but not LCS algorithm
int LCSDP(int arr[], int n)
{
    int lis[n];
    int subseq[n];
    lis[0] = 1;
    subseq[0] = -1;
    for(int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[j]+1 > lis[i])
            {
                lis[i] = lis[j]+1;
                subseq[i] = j;
            }
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++)
    if (lis[i] > lis[max])
    max = i;
    int temp = max;
    stack<int> st;
    while(temp != 0)
    {
        st.push(arr[temp]);
        temp = subseq[temp];
    }
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
    return lis[max];

}

int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    LIS(arr, n); 
    return 0;
}

