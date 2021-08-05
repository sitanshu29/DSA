//Suffix Array
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000001
#define MAXLG 21

struct entry
{
    int r[2];
    int p;
}L[MAXN];

int P[MAXLG][MAXN], N;
string s;

bool cmp(const entry &a, const entry &b)
{
    return a.r[0] == b.r[0] ? (a.r[1] < b.r[1]? 1: 0):(a.r[0] < b.r[0]? 1:0);
}

vector<int> getSuffixArray()
{
    N = s.length();
    for(int i = 0; i < N; i++)
    P[0][i] = s[i]-'a';
    int stp, cnt;
    for(stp = 1, cnt = 1; cnt>> 1 < N; cnt<<= 1, stp++)
    {
        for(int i = 0; i < N; i++)
        {
            L[i].r[0] = P[stp-1][i];
            L[i].r[1] = i+cnt < N? P[stp-1][i+cnt]:-1;
            L[i].p = i;
        }
        sort(L, L+N, cmp);

        for(int i = 0; i < N; i++)
        {
            P[stp][L[i].p] = i > 0 && L[i].r[0] == L[i-1].r[0] && L[i].r[1] == L[i-1].r[1] ?
            P[stp][L[i-1].p]: i;
        }
    }
    vector <int> ans;
    for(int i= 0; i < N; i++)
    {
        ans.push_back(P[stp-1][i]);
    }
    return ans;

}

int main()
{
    cin >> s;
    vector<int> suffArr = getSuffixArray();
    for(int i = 0; i < N; i++)
    cout << suffArr[i] << " ";
    cout << endl;
}