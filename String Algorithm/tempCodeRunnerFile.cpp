//Determine number of unique substrings in a string using String Hashing
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair

int uniqueSubstr(string s)
{
    int prime = 31;
    int mod = (int)1e9+9;
    int n = s.length();
    vector<ll> pow(n);
    pow[0] = 1;
    for(int i = 1; i < n; i++)
    pow[i] = (pow[i-1]*p)%mod;

    vector<ll> hash(n+1, 0);
    for(int i = 0; i < n; i++)
    {
        hash[i+1] = (hash[i]+ (s[i]-'a'+1)*pow[i])%mod;
    }

    int cnt = 0;

    for(int l = 1; l <= n; l++)
    {
        set<int> st;
        for(int i = 0; i < n-l+1; i++)
        {
            ll curr_h = (hash[i+l] - hash[i] + mod)%mod;
            curr_h = (curr_h*pow[n-i-1])%mod;
            st.insert(curr_h);
        }
        cnt+= st.size();
    }

    return cnt;

}

int main()
{
    string s;
    cin >> s;
    cout << uniqueSubstr(s) << endl;
    return 0;
}