//Range Max Lazy Propagtion Segment Tree
#include <bits/stdc++.h>
using namespace std;
int lazy[100000] = {0};

void updateLazy(int st[], int s, int e, int qs, int qe, int value, int index)
{
    if (lazy[index]!= 0)
    {
        st[index]+= lazy[index];
        if (s!= e)
        {
            lazy[2*index+1]+= lazy[index];
            lazy[2*index+2]+= lazy[index];
        }
        lazy[index] = 0;
    }

    if (qe < s || qs > e)
    return;
    
    if (s >= qs && e <= qe)
    {
        st[index]+= value;
        if (s!= e)
        {
            lazy[2*index+1]+= value;
            lazy[2*index+2]+= value;
        }
        return;
    }

    int mid = s+(e-s)/2;
    updateLazy(st, s, mid, qs, qe, value, 2*index+1);
    updateLazy(st, mid+1, e, qs, qe, value, 2*index+2);
    st[index] = max(st[2*index+1], st[2*index+2]);
}

int RMQ(int st[], int s, int e, int qs, int qe, int index)
{
    if (lazy[index]!= 0)
    {
        st[index]+= lazy[index];
        if (s!= e)
        {
            lazy[2*index+1]+= lazy[index];
            lazy[2*index+2]+= lazy[index];
        }
        lazy[index] = 0;
    }
    
    if (qe < s || qs > e || qs > qe)
    return INT_MIN;

    if (s >= qs && e <= qe)
    return st[index];

    int mid = s+(e-s)/2;
    return max(RMQ(st, s, mid, qs, qe, 2*index+1), RMQ(st, mid+1, e, qs, qe, 2*index+2));
}

int constructSTUtill(int arr[], int st[], int s, int e, int index)
{
    if (s == e)
    {
        st[index] = arr[s];
        return st[index];
    }
    int mid = s+(e-s)/2;
    st[index] = max(constructSTUtill(arr, st, s, mid, 2*index+1), constructSTUtill(arr, st, mid+1, e, 2*index+2));
    return st[index];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int size = 2*(int)pow(2, x) -1;

    int *st = new int[size];
    memset(st, INT_MIN, sizeof(st));
    constructSTUtill(arr, st, 0, n-1, 0);
    return st;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++)
    cin >> arr[i];

    int *st = constructST(arr, n);
    int query;
    cin >> query;
    int qs, qe, qi, value;
    char x;	//M - for RMQ , U -update
    while(query--)
    {
        cin >> x;
        if (x == 'M')
        {
			cin >> qs >> qe;
        	cout << RMQ(st, 0, n-1, qs, qe, 0) << endl;
        }
        else
        {
        	cin >> qs >> qe >> value;
        	updateLazy(st, 0, n-1, qs,qe, value, 0);
		}
    }

    return 0;
}