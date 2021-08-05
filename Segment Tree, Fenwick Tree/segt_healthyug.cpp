#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int arr[N]; // stores elems from 0 to n-1

int segt[4 * N]; //v used in each function starts from 1, also l and r are from 0 to n-1

void update(int v, int l, int r, int idx, int val)
{
    if (idx > r || idx < l)
        return;

    if (l == idx && r == idx)
    {
        segt[v] = val;
        return;
    }

    int mid = (l + r) / 2;
    update(2 * v, l, mid, idx, val);
    update(2 * v + 1, mid + 1, r, idx, val);

    segt[v] = segt[2 * v] + segt[2 * v + 1];
}

int query(int v, int ql, int qr, int l, int r)
{
    if (l >= ql && r <= qr)
        return segt[v];

    if (l > qr || r < ql)
        return 0;

    int mid = (l + r) / 2;

    return query(2 * v, ql, qr, l, mid) + query(2 * v + 1, ql, qr, mid + 1, r);
}

void build(int v, int l, int r)
{
    if (l == r)
    {
        segt[v] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);

    segt[v] = segt[2 * v] + segt[2 * v + 1];
}