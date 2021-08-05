#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int s[120005];
struct Element
{
    int val, ind;
};
struct Query
{
    int x, y, k, num;
};
bool compar1(Element a, Element b)
{
    return a.val < b.val;
}
bool compar2(Query q1, Query q2)
{
    return q1.k < q2.k;
}

/// Say that every element in a is greater than k
int build(int lo, int hi, int i)
{
    if (lo > hi) {
        return 0;
    }
    if (lo == hi) {
        return s[i] = 1;
    }
    int mid = (lo + hi) / 2;
    return (s[i] = (build(lo, mid, 2*i+1) + build(mid+1, hi, 2*i+2)));
}

/// Later update the elements which are less than k
void update(int x, int y, int lo, int hi, int i)
{
    if (lo > hi)
        return;
    if (y<lo || x>hi)
        return;

    if (x<=lo && y>=hi) {
        s[i] = 0;
        return;
    }

    int mid = (lo + hi) / 2;
    update(x, y, lo, mid, 2*i+1);
    update(x, y, mid+1, hi, 2*i+2);
    s[i] = s[2*i+1] + s[2*i+2];
}

/// Return number of elements greater than k in range x to y.
int sum(int x, int y, int lo, int hi, int i)
{
    if (lo > hi || y<lo || x>hi)
        return 0;
    if (x<=lo && y>=hi)
        return s[i];

    int mid = (lo + hi)/2;

    return sum(x, y, lo, mid, 2*i+1) + sum(x, y, mid+1, hi, 2*i+2);
}

int main()
{
    int n, q;
    cin >> n;
    vector<Element> a(n);
    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        a[i].val = v;
        a[i].ind = i;
    }
    sort(a.begin(), a.end(), compar1);
    cin >> q;
    vector<Query> query(q);
    for (int i = 0; i < q; ++i) {
        int x, y, k;
        cin >> x >> y >> k;
        query[i].x = x - 1;
        query[i].y = y - 1;
        query[i].k = k;
        query[i].num = i;
    }
    sort(query.begin(), query.end(), compar2);


    build(0, n-1, 0);
    int pos= 0;
    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        while(pos < n && (a[pos].val <= query[i].k)) {
            update(a[pos].ind, a[pos].ind, 0, n-1, 0);
            ++pos;
        }
        ans[query[i].num] = sum(query[i].x, query[i].y, 0, n-1, 0);
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}

