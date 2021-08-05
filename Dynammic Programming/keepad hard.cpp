#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	vector<int> adj[10];
	adj[0].push_back(0);adj[0].push_back(8);adj[1].push_back(1);adj[1].push_back(2);adj[1].push_back(4);
	adj[2].push_back(1);adj[2].push_back(2);adj[2].push_back(3);adj[2].push_back(5);
	adj[3].push_back(2);adj[3].push_back(3);adj[3].push_back(6);adj[4].push_back(1);adj[4].push_back(4);adj[4].push_back(5);adj[4].push_back(7);
	adj[5].push_back(2);adj[5].push_back(4);adj[5].push_back(5);adj[5].push_back(6);adj[5].push_back(8);adj[6].push_back(3);
	adj[6].push_back(5);adj[6].push_back(6);adj[6].push_back(9);adj[7].push_back(4);adj[7].push_back(7);adj[7].push_back(8);
	adj[8].push_back(7);adj[8].push_back(9);adj[8].push_back(0);adj[8].push_back(5);adj[8].push_back(8);adj[9].push_back(6);adj[9].push_back(9);adj[9].push_back(8);
	while(t--)
	{
		int n;
		cin >> n;
		long long dp[n+1][10];
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < 10; i++)
		dp[1][i] = 1;
		for(int i = 2; i <= n; i++)
		{
			for(int j = 0; j< 10; j++)
			{
				for(auto it:adj[j])
				{
					dp[i][j]+= dp[i-1][it];
				}
			}
		}
//		for(int i = 0; i <= n; i++)
//		{
//			for(int j = 0; j < 10; j++)
//			cout << dp[i][j] << " ";
//			cout << endl;
//		}
		long long ans = 0;
		for(int i = 0; i < 10; i++)
		ans+= dp[n][i];
		
		cout << ans << endl;
	}
}
