//Number of BSTs possible with N keys
//Number of Unlabelled Binary Trees Possible with N nodes
// Number of Labelled Binary Tree - catalan(n)*fact(n)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>

int catalan[1001];

long long nCr(ll n, ll k)
{
    if (k > n-k)
    k = n-k;

    ll res = 1;
    for(ll i =0; i < res; i++)
    {
        res*= (n-i);
        res/= (i+1);
    }

    return res;
}


int calculate(int n)
{
    if (catalan[n] != 0)
    return catalan[n];

    for(int i = 0; i < n; i++)
    {
        catalan[n]+= calculate(i)*calculate(n-i-1);
    }

    return catalan[n];


}

int main()
{
    for(int i = 0; i < 1001; i++)
    catalan[i] = 0;

    catalan[0] = 1, catalan[1] = 1;
    int n;
    cin >> n;
    cout << calculate(n) << endl;
    return 0;
}