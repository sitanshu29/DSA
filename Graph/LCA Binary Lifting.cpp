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
#define clr(val) memset(val,0,sizeof(val))
const ll MAX = 1000009, MOD = 1e9 + 7;
const int N = 2e5;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


vector<int> g[N];
const int LG = 20;
// Using 1 based indexing

int lvl[N], dp[N][LG];

void dfs(int u, int p)
{
    lvl[u] = 1+lvl[p];
    dp[u][0] = p;

    for(int v : g[u])
    {
        if (v == p)
        continue;
        dfs(v, u);
    }
}


int lca(int u, int v)
{
    int i, lg;

    if (lvl[u] < lvl[v])
    swap(u, v);

    for(lg = 0; (1<< lg) <= lvl[u]; lg++);
    lg--;

    for(int i = lg; i>= 0; i--)
    {
        if (lvl[u] - (1<< i) >= lvl[v])
        u = dp[u][i];
    }
    if (u == v)
    return v;

    for(int i = lg; i >= 0; i--)
    {
        if (dp[u][i] != -1 && dp[u][i] != dp[v][i])
        {
            u = dp[u][i]; v = dp[v][i];
        }
    }

    return dp[u][0];
    
}

int distance(int u, int v)
{
    int w = lca(u, v);
    return lvl[u]+lvl[v]-2*lvl[w];
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, u, v;
    cin >> n;
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    // Using 1 based indexing
    for(int i = 0; i < n+1; i++)
    for(int j =0; j < LG; j++)
    dp[i][j] = -1;

    lvl[0] = -1;
    dfs(1, 0);

    for(int i = 1; i <= n; i++)
    for(int j = 1; j < LG; j++)
    {
        if (dp[i][j-1] != -1 )
        dp[i][j] = dp[dp[i][j-1]][j-1];
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j < LG; j++)
        cout << dp[i][j] << " ";

        cout << endl;
    }

    int q;
    cin >> q;
    int x, y, z;
    while(q--)
    {
        cin >> x >> y >> z;
        int ans = lca(x, y)^lca(y, z)^lca(x, z);
        cout << ans << endl;
    }
    return 0;
}