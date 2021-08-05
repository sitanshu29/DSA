//Manachers's Algorithm, Longest Polindromic Substring
#include <bits/stdc++.h>
using namespace std;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    n = 2*n+1;
    int lps[n];
    int centre = 1, centreRight = 1 , currentLeft, maxPLength = 1, LPSCentrepos = 1;
    lps[0] = 0, lps[1] = 1;
    for(int i = 2; i < n; i++)
    {
        lps[i] = 0;
        if (i < centreRight)
        lps[i] = min(lps[2*centre -i], centreRight-i);

        while(i+lps[i] < n-1 && i-lps[i] > 0 && ((i+lps[i]+1)%2 == 0 || s[(i+lps[i]+1)/2] == s[(i-lps[i]-1)/2]))
        lps[i]++;

        if (i+lps[i] > centreRight)
        {
            centre = i;
            centreRight = i+lps[i];
        }
        if (lps[i] > maxPLength)
        {
            maxPLength = lps[i];
            LPSCentrepos = i;
        }
    }
    cout << maxPLength << endl;
    cout << s.substr((LPSCentrepos-maxPLength)/2, maxPLength) << endl;
}


int main()
{
    OJ;
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}