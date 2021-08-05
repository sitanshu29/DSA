#include <bits/stdc++.h>
using namespace std;
//lazy propagation range sum
const int N = 1e5 + 5;

int segt[4 * N] = {};
bool lazy[4 * N] = {};
int upd[4 * N] = {};

int arr[N];

void apply(int v, int l, int r, int val)
{
    segt[v] += val * (r - l + 1);

    if (l != r)
    {
        lazy[v] = 1;
        upd[v] += val;
    }
}

void pushdown(int v, int l, int r)
{
    if (lazy[v])
    {
        lazy[v] = 0;
        int mid = (l + r) / 2;
        apply(2 * v, l, mid, upd[v]);
        apply(2 * v + 1, mid + 1, r, upd[v]);
        upd[v] = 0;
    }
}

void update(int v, int l, int r, int ql, int qr, int val)
{
    if (l > qr || r < ql)
        return;

    if (l >= ql && r <= qr)
    {
        apply(v, l, r, val);
        return;
    }
    pushdown(v, l, r);
    int mid = (l + r) / 2;

    update(2 * v, l, mid, ql, qr, val);
    update(2 * v + 1, mid + 1, r, ql, qr, val);

    segt[v] = segt[2 * v] + segt[2 * v + 1];
}

int query(int v, int ql, int qr, int l, int r)
{
    if (l > qr || r < ql)
        return 0;

    if (l >= ql && r <= qr)
    {
        return segt[v];
    }
    pushdown(v, l, r);

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
    build(2 * v, l, mid + 1);
    build(2 * v + 1, mid + 1, r);

    segt[v] = segt[2 * v] + segt[2 * v + 1];
}