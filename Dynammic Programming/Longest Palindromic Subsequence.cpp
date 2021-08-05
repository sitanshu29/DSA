#include <bits/stdc++.h>
using namespace std;
#define ll long long;

int maxSumAlternating(int arr[], int n)
{
	pair<int, int> dp[n];		// inc, dec
	for(int i = 0; i < n; i++)
	{
		dp[i].first = 0;
		dp[i].second = arr[i];
	}
	
	for(int i = 1; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if (arr[j] > arr[i] && dp[j].second+arr[i] > dp[i].first)
			dp[i].first = dp[j].second+arr[i];
			
			if (dp[j].first!= 0 && arr[j] < arr[i] && dp[j].first+arr[i] > dp[i].second)
			dp[i].second = dp[j].first+arr[i];
		}
	}
	
	int ans = INT_MIN;
	for(int i = 0; i < n; i++)
	ans = max({ans, dp[i].first, dp[i].second});
	
	return ans;
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++)
        cin >> arr[i];
        
        cout << maxSumAlternating(arr, n) << endl;
    }
    return 0;
}
