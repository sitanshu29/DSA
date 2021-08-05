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

vector<int> z;
string s, p, combine;
int ans;
void calculateZ()
{
    int n = s.length();
    ans = -1;
    for(int i = 1, l = 0, r = 0; i < 2*n+1; i++)
    {
        if (i <= r)
        {
            z[i] = min(r-i+1, z[i-l]);
        }
        while(i+z[i] < 2*n+1 && combine[z[i]] == combine[i+z[i]])
        ++z[i];

        if (i+z[i]-1 > r)
        {
            l = i; r = i+z[i]-1;
        }

        if (i+z[i] == 2*n+1)
        {
            ans = z[i];
            break;
        }

    }
}


void solve()
{
    cin >> s;
    p = s;
    reverse(p.begin(), p.end());
    combine = p +'#'+s;
    z.clear();
    z.resize(combine.length(), 0);
    calculateZ();
    for(int i = ans; i < p.length(); i++)
    s+= p[i];

    cout << s << endl;

    

}



int main()
{
    //OJ;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t;
    cin >> t;
    while(t--)
    {
        solve();
    }  
    return 0;
}