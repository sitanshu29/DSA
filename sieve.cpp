#include <bits/stdc++.h> //Sieve Program... Change thee main and check
using namespace std;
#define ll long long
#define MAX 1000001

vector<int> spf(MAX);

void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < MAX; i++)
		spf[i] = i;

	for (int i = 4; i < MAX; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAX; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < MAX; j += i)
			{
				if (spf[j] == j)
					spf[j] = i;
			}
		}
	}
}

bool check(int x, int k)
{
	int count = 0;
	while (x != 1)
	{
		++count;
		cout << spf[x] << " ";
		x /= spf[x];
	}
	cout << endl;
	cout << count << endl;
	if (count >= k)
		return 1;
	else
		return 0;
}

int main()
{
	sieve();
	int t;
	cin >> t;
	while (t--)
	{
		int x, k;
		cin >> x >> k;
		if (k >= x)
			cout << 0 << endl;
		else
			cout << "res " << check(x, k) << endl;
	}
	return 0;
}