//Segment Tree (Range Min Query With Updates)
#include <bits/stdc++.h>
using namespace std;

void update(int arr[], int st[], int s, int e, int qi, int value, int index)
{
	if (qi < s || qi > e)
	{
		cout << "Update Error\n";
		return;
	}
	if (s == e)
	{
		arr[s] = value;
		st[index] = value;
	}
	else
	{
		int mid = s+(e-s)/2;
		if (s <= qi && qi<= mid)
		{
			update(arr, st, s, mid, qi, value, 2*index+1);
		}
		else
		update(arr, st, mid+1, e, qi, value, 2*index+2);
		
		st[index] = min(st[2*index+1], st[2*index+2]);
	}
	return;
}

int RMQUtill(int st[], int s, int e, int qs, int qe, int index)
{
    if(qs <=s && qe >= e)
    return st[index];
    if (qe < s || e < qs)
    return INT_MAX;

    int mid = s + (e-s)/2;

    return min(RMQUtill(st, s, mid, qs, qe, 2*index+1), RMQUtill(st, mid+1, e, qs, qe, 2*index+2));
}

int RMQ(int st[], int n, int qs, int qe)
{
    if (qs < 0 || qe > n-1 || qs > qe)
    return INT_MAX;

    return RMQUtill(st, 0, n-1, qs, qe, 0);
}

int constructSTUtill(int arr[], int st[], int low, int high, int index)
{
    if (low == high)
    {
        st[index] = arr[low];
        return st[index];
    }
    int mid = low + (high-low)/2;
    st[index] = min(constructSTUtill(arr, st, low, mid, 2*index+1), constructSTUtill(arr, st, mid+1, high, 2*index+2));
    return st[index];
}

int *constructST(int arr[], int n)
{
    int x = (int)(ceil(log2(n)));
    int size = 2*(int)pow(2, x) -1;

    int *st = new int[size];
    memset(st, INT_MAX, sizeof(st));
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
        	cout << RMQ(st, n, qs, qe) << endl;
        }
        else
        {
        	cin >> qi >> value;
        	update(arr, st, 0, n-1, qi, value, 0);
		}
    }

    return 0;
}