//Range Query for Largest Sum Contigious Subarray
#include <bits/stdc++.h>
using namespace std;

struct data
{
	int sum, pref, suff, ans;
	
	data(int x)
	{
		sum = x; pref = x; suff = x; ans = x;
	}
	
	data()
	{
		
	}
};

struct data combine(struct data a, struct data b)
{
	struct data res;
	res.sum = a.sum + b.sum;
	res.pref = max(a.pref, a.sum+b.pref);
	res.suff = max(b.suff, b.sum+a.suff);
	res.ans = max({a.ans, b.ans, a.suff+b.pref});
	
	return res;
}

void constructSTUtill(int arr[], struct data *st, int s, int e, int idx)
{
	if (s == e)
	{
		st[idx] = data(arr[s]);
		return;
	}
	
	int mid = s+(e-s)/2;
	constructSTUtill(arr, st, s, mid, 2*idx+1);
	constructSTUtill(arr, st, mid+1, e, 2*idx+2);
	st[idx] = combine(st[2*idx+1], st[2*idx+2]);
	
}

struct data *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	int size = 2*(int)pow(2, x) -1;
	
	data *st = new data[size];
	for(int i = 0; i < size; i++)
	st[i] = data(INT_MIN);
	
	constructSTUtill(arr, st, 0, n-1, 0);
	
	return st;
}

struct data query(struct data *st, int s, int e, int qs, int qe, int idx)
{
	if (e < qs || s > qe)
	return data(INT_MIN);
	
	if (s >= qs && e <= qe)
	return st[idx];
	
	int mid = s+(e-s)/2;
	
	return combine(query(st, s, mid, qs, qe, 2*idx+1), query(st, mid+1, e, qs, qe, 2*idx+2));
}

void update(int arr[], struct data *st, int s, int e, int qi, int value, int idx)
{
	if (s > qi || e < qi)
	return;
	
	if (s == e)
	{
		arr[s] = value;
		st[idx] = data(value);
		return;
	}
	
	int mid = s+(e-s)/2;
	if (qi <= mid)
	update(arr, st, s, mid, qi, value, 2*idx+1);
	else
	update(arr, st, mid+1, e, qi, value, 2*idx+2);
	
	st[idx] = combine(st[2*idx+1], st[2*idx+2]);
}

int main()
{
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++)
	cin >> arr[i];
	
	struct data *st = constructST(arr, n);
	int qs, qe, qi, value; char x;
	
	while(1)
	{
		cin >> x;
		if (x == 'q')
		{
			cin >> qs >> qe;
			cout << query(st, 0, n-1, qs, qe, 0).ans << endl;
		}
		else if (x == 'u')
		{
			cin >> qi >> value;
			update(arr, st, 0, n-1, qi, value, 0);
		}
		else
		break;
	}
}


