//Range Queries LCM
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0)
	return b;
	return gcd(b%a, a);
}

void update(int *arr, int *st, int s, int e, int qi, int value, int idx)
{
	if (s == e)
	{
		arr[s] = value;
		st[idx] = value;
		return;
	}
	
	int mid = s+ (e-s)/2;
	if (qi <= mid)
	update(arr, st, s, mid, qi, value, 2*idx+1);
	else
	update(arr, st, mid+1, e, qi, value, 2*idx+2);
	
	st[idx] = (st[2*idx+1]*st[2*idx+2])/gcd(st[2*idx+1], st[2*idx+2]);
}

int query(int *st, int s, int e, int qs, int qe, int idx)
{
	if (qs > e || s > qe)
	return 1;
	
	if (s >= qs && qe >= e)
	return st[idx];
	
	int mid = s+(e-s)/2;
	int a = query(st, s, mid, qs, qe, 2*idx+1);
	int b = query(st, mid+1, e, qs, qe, 2*idx+2);
	return a*b/gcd(a, b);
}

void constructSTUtill(int arr[], int *st, int s, int e, int idx)
{
	if (s == e)
	{
		st[idx] = arr[s];
		return;
	}
	
	int mid = s+ (e-s)/2;
	constructSTUtill(arr, st, s, mid, 2*idx+1);
	constructSTUtill(arr, st, mid+1, e, 2*idx+2);
	
	st[idx] = (st[2*idx+1]*st[2*idx+2])/gcd(st[2*idx+1], st[2*idx+2]);
}

int *constructST(int arr[], int n)
{
	int x = (int)(ceil(log2(n)));
	int size = 2*(int)(pow(2, x)) -1;
	
	int *st = new int[size];
	memset(st, 1, sizeof(st));
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
	int qs, qe, qi, value; char x;
	
	while(1)
	{
		cin >> x;
		if (x == 'q')
		break;
		if (x == 'r')
		{
			cin >> qs >> qe;
			cout << query(st, 0, n-1, qs, qe, 0) << endl;
		}
		else
		{
			cin >> qi >> value;
			update(arr, st, 0, n-1, qi, value, 0);
		}
	}
}
