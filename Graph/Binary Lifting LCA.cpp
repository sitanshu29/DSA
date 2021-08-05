//@Author- sitanshu
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define mii map<int, int>
#define umii unordered_map<int, int>
#define vi vector<int>
#define vl vector<ll>
#define clr(val) memset(val, 0, sizeof(val))
const ll MAX = 1000009, MOD = 1e9 + 7;
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

vector<vector<int>> adj;
vector<vector<int>> dp;
vector<int> depth;
int LOG;

void dfs(int s, int p)
{
    if (p != -1)
    {
        depth[s] = depth[p] + 1;
        dp[s][0] = p;

        for (int i = 1; i < LOG; i++)
        {
            if (dp[s][i - 1] != -1)
            {
                dp[s][i] = dp[dp[s][i - 1]][i - 1];
            }
        }
    }
    for (auto i : adj[s])
    {
        if (i != p)
        {
            dfs(i, s);
        }
    }
}

int main()
{
    OJ;
    int n, m, x, y;
    cin >> n;

    LOG = 0;
    while ((1 << LOG) <= n)
        ++LOG;
    adj = vector<vector<int>>(n);
    dp = vector<vector<int>>(n, vector<int>(LOG, -1));
    depth = vector<int>(n);
    depth[0] = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            cin >> x;
            adj[i].pb(x);
            adj[x].pb(i);
        }
    }

    dfs(0, -1);

    int q;
    cin >> q;

    while (q--)
    {
        cin >> x >> y;

        if (depth[x] < depth[y])
            swap(x, y);

        int k = depth[x] - depth[y];
        for (int i = 0; i < LOG; i++)
        {
            if (k & (1 << i))
                x = dp[x][i];
        }
        /*
        //Any of these 3 ways of for loop could be used
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k & (1 << i))
                x = dp[x][i]; 
        }
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (k >= (1 << i))
            {
                x = dp[x][i];
                k -= (1 << i);
            }
        }
        */
        if (x == y)
        {
            cout << x << endl;
            continue;
        }

        //Going to the nearest child of LCA
        for (int i = LOG - 1; i >= 0; i--)
        {
            if (dp[x][i] != dp[y][i])
            {
                x = dp[x][i];
                y = dp[y][i];
            }
        }
        cout << dp[x][0] << endl;
    }

    return 0;
}