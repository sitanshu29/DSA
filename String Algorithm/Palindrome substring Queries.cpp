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
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);


void solve()
{
    string s;
    cin >> s;
    int mod = (int)1e9+7;
    int n = s.length();
    vector<ll> power(n), h(n+1, 0), h2(n+1, 0);
    power[0] = 1;
    for(int i = 1; i < n; i++)
    power[i] = (power[i-1]*31)%mod;

    for(int i = 0; i < n; i++)
    {
        h[i+1] = (h[i] + (ll)s[i]*power[i])%mod;
        h2[i+1] = (h2[i] + (ll)s[n-i-1]*power[i])%mod;
    }

    int q;
    cin >> q;
    int b, e, l, r;
    ll p_h, c_h;
    while(q--)
    {
        cin >> b >> e;
        l = n-e-1; r = n-b-1;
        p_h = (h[e+1]-h[b]+mod)%mod;
        c_h = (h2[r+1]-h2[l]+mod)%mod;

        if (b > l)
        {
            c_h = (c_h*power[b-l])%mod;
        }
        else
        {
            p_h = (p_h*power[l-b])%mod;
        }

        if (c_h == p_h)
        cout << "Yes" << endl;
        else
        cout << "No" << endl;
        

    }

}



int main()
{
    OJ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    t = 1;
    while(t--)
    {
        solve();
    }  
    return 0;
}