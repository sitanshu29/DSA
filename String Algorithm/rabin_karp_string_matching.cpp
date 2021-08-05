#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> findOccurence(string s, string pattern)
{
    int p = 31, mod = (int)1e9+7;
    vector<int> ans;
    if (s.length() < pattern.length())
    return ans;
    int n = s.length(), m = pattern.length();
    vector<ll> power(n);
    power[0] = 1;
    for(int i = 1; i < n; i++)
    power[i] = (power[i-1]*p)%mod;

    vector<ll> hash(n+1, 0);
    for(int i = 0; i < n; i++)
    hash[i+1] = (hash[i]+ (s[i]-'a'+1)*power[i])%mod;

    ll hash_p = 0;
    for(int i = 0; i < m; i++)
    {
        hash_p = (hash_p + (pattern[i]-'a'+1)*power[i])%mod;
    }

    for(int i = 0; i < n-m+1; i++)
    {
        ll curr_hash = (hash[i+m]-hash[i]+mod)%mod;

        if (curr_hash == (hash_p*power[i])%mod)
        ans.push_back(i);
    }

    return ans;
}


int main()
{
    int t;
    cin >> t;
    while(t--){
    string s, pattern;
    cin >> s >> pattern;

    vector<int> occurence = findOccurence(s, pattern);
    if (occurence.size() == 0)
    {
        cout << "Not Found\n";
       
    }
    else{
    cout << occurence.size() << endl;
    for(int i = 0; i < occurence.size(); i++)
    cout << occurence[i]+1 << " ";
    cout << endl;
    }
    }
    return 0;
}