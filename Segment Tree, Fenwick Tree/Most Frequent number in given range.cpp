//Most frequent number in given range in a non decreasing array
//SPOJ FREQUENT
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
struct Node
{
	pair<int, int> p[3];
	
	Node(int x)
	{
		p[0].f = x;
		p[0].s = 1;
		p[1].f = x, p[1].s = 1;
		p[2].f = x; p[2].s = 1;
	}
	Node(int x, int y)
	{
		p[0].s = -1;
	}
	Node()
	{
		
	}
};

int arr[100001], n, m;
vector<Node> st(5*100001, Node(-1, -1));

Node combine(Node a, Node b)
{
	if (a.p[0].s == -1)
	return b;
	if (b.p[0].s == -1)
	return a;
	
	Node res;
	if (a.p[1].f == b.p[2].f) 
	{
		res.p[0].f = a.p[0].f;
		res.p[0].s = a.p[0].s + b.p[0].s;
		res.p[1].f = a.p[1].f; res.p[1].s = res.p[0].s;
		res.p[2] = res.p[1];
	}
	else if (a.p[2].f == b.p[1].f)
	{
		if (a.p[1].f == a.p[2].f)
		{
			res.p[1].f = a.p[1].f; res.p[1].s = a.p[1].s + b.p[1].s;
			res.p[2].f = b.p[2].f; res.p[2].s = b.p[2].s;
			res.p[0].f = (max(res.p[1].s, b.p[0].s) == res.p[1].s?res.p[1].f:b.p[0].f);
			if (res.p[0].f == res.p[1].f)
			res.p[0].s = res.p[1].s;
			else
			res.p[0].s = b.p[0].s; 
		}
		else if (b.p[1].f == b.p[2].f)
		{
			res.p[1].f = a.p[1].f; res.p[1].s = a.p[1].s;
			res.p[2].f = b.p[2].f; res.p[2].s = b.p[2].s + a.p[2].s;
			res.p[0].f = (max(res.p[2].s, a.p[0].s) == res.p[2].s?res.p[2].f:a.p[0].f);
			if (res.p[0].f == res.p[2].f)
			res.p[0].s = res.p[2].s;
			else
			res.p[0].s = a.p[0].s; 
		}
		else
		{
			res.p[1].f = a.p[1].f; res.p[1].s = a.p[1].s;
			res.p[2].f = b.p[2].f; res.p[2].s = b.p[2].s ;
			if (max({a.p[0].s, b.p[0].s, a.p[2].s+b.p[1].s}) == a.p[2].s+b.p[1].s)
			{
				res.p[0].f = a.p[2].f; res.p[0].s = a.p[2].s+b.p[1].s;
			}
			else
			{
				res.p[0].f = (max(a.p[0].s, b.p[0].s) == a.p[0].s?a.p[0].f:b.p[0].f);
				res.p[0].s = (res.p[0].f == a.p[0].f?a.p[0].s:b.p[0].s);
			}
		}
	}
	else
	{
		res.p[1].f = a.p[1].f; res.p[1].s = a.p[1].s;
		res.p[2].f = b.p[2].f; res.p[2].s = b.p[2].s;
		res.p[0].f = (max(a.p[0].s, b.p[0].s) == a.p[0].s?a.p[0].f:b.p[0].f);
		res.p[0].s = (res.p[0].f == a.p[0].f?a.p[0].s:b.p[0].s);
		
	}
	return res;
}

void build(int s, int e, int i)
{
	if (s == e)
	{
		st[i] = Node(arr[s]);
		return;
	}
	int mid = s+(e-s)/2;
	build(s, mid, 2*i+1);
	build(mid+1, e, 2*i+2);
	
	st[i] = combine(st[2*i+1], st[2*i+2]);
}

Node query(int s, int e, int qs, int qe, int i)
{
	if (qs > e || s > qe)
	return Node(-1, -1);
	if (s >= qs && e <= qe)
	return st[i];
	
	int mid = s+(e-s)/2;
	return combine(query(s, mid, qs, qe, 2*i+1), query(mid+1, e, qs, qe, 2*i+2));
}

int main()
{
	while(1)
	{
		st.assign(st.size(), Node(-1, -1));
		cin >> n;
		if (n == 0)
		return 0;
		cin >> m;
		for(int i = 0; i < n; i++)
		cin >> arr[i];
		build(0, n-1, 0);
	
		int x, y;
		for(int i = 0; i < m; i++)
		{
			cin >> x >> y;
			cout << query(0, n-1, x-1, y-1, 0).p[0].s << endl;
		}
	}
}




