//SPOJ DQUERY
//Could be also done using a set type segment tree but time complex becomes O(n.log(n)^2)
//Implementation using an ofline segment tree algorithm

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second


pair<int, pair<int, int>> q[200001];
int arr[100001], n, m, ans[200001];
int st[5*100001] = {}, used[1000001] = {};


void update(int s, int e, int x, int val, int i)
{
	if (s == e)
	{
		st[i] = val;
		return;
	}
	
	int mid = s+(e-s)/2;
	if (x <= mid)
	update(s, mid, x, val, 2*i);
	else
	update(mid+1, e, x, val, 2*i+1);
	
	st[i] = st[2*i]+st[2*i+1];
}

int rangeSum(int qs, int qe, int s, int e, int i)
{
	if (qs > e || qe < s)
	return 0;
	
	if (s>= qs && e <= qe)
	return st[i];
	
	
	
	int mid = s+(e-s)/2;
	
	return rangeSum(qs, qe, s, mid, 2*i)+ rangeSum(qs, qe, mid+1, e, 2*i+1);
}


int main()
{
	cin >> n;
	for(int i = 1; i <= n; i++)
	cin >> arr[i];
	
	cin >> m;
	for(int i = 1; i <= m; i++)
	{
		cin >> q[i].f >> q[i].s.f;
		q[i].s.s = i;
	}
	
	sort(q+1, q+m+1, [](const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)
	{
		if (a.s.f != b.s.f)
		return a.s.f < b.s.f;
		
		return a.f < b.f;	
	});
	
	
	int j = 1;
	for(int i = 1; i <= m; i++)
	{
		while(j <= q[i].s.f)
		{
			if (!used[arr[j]])
			{
				update(1, n, j, 1, 1);
				used[arr[j]] = j;
			}
			else
			{
				update(1, n, used[arr[j]], 0, 1);
				update(1, n, j, 1, 1);
				used[arr[j]] = j;
			}
			++j;
		}
		
		ans[q[i].s.s] = rangeSum(q[i].f, q[i].s.f, 1, n, 1);
	}
	
	
	for(int i = 1; i <= m; i++)
	cout << ans[i] << endl;
	
	
	
}


