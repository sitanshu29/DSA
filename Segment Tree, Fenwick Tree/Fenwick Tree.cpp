#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second

int maxIdx(int n)
{
	int x = (int)(log2(n));

	return (int)pow(2, x);
}

class BIT
{
public:
	int size;
	int *table;

	BIT(int n)
	{
		this->size = n;
		this->table = new int[size + 1];

		for (int i = 0; i <= n; i++)
			table[i] = 0;
	}

	void update(int idx, int val) //Adds to the idx (doesn't replace)
	{
		idx += 1;
		while (idx <= size)
		{
			table[idx] += val;
			idx += (idx & -idx);
		}
	}

	int prefSum(int idx)
	{
		idx += 1;
		int sum = 0;
		while (idx > 0)
		{
			sum += table[idx];
			idx -= (idx & -idx);
		}
		return sum;
	}

	int rangeSum(int s, int e)
	{
		if (s == 0)
			return prefSum(e);
		return prefSum(e) - prefSum(s - 1);
	}

	BIT(int arr[], int n)
	{
		this->size = n;
		table = new int[size + 1];

		for (int i = 0; i <= n; i++)
			table[i] = 0;
		for (int i = 0; i < n; i++)
			update(i, arr[i]);
	}

	void rangeUpdate(int s, int e, int val)
	{
		update(s, val);
		update(e + 1, -val);
	}

	int freqAtPos(int idx) //Can be also done using prefSum(idx) - prefSum(idx-1) or by mainting a array of freq at each index
	{
		idx += 1;
		int ans = table[idx];
		int z = idx - (idx & -idx);
		idx--;
		while (idx != z)
		{
			ans -= table[idx];
			idx -= (idx & -idx);
		}

		return ans;
	}

	//Finding Maximum Frequency with given cumulative frequency

	int findIdx(int cumfreq)
	{
		int idx = 0;
		int bitMask = maxIdx(size);

		while (bitMask != 0)
		{
			int tIdx = idx + bitMask;
			bitMask >>= 1;

			if (tIdx > size)
				continue;

			if (cumfreq >= table[tIdx])
			{
				idx = tIdx;
				cumfreq -= table[idx];
			}
		}

		if (cumfreq != 0)
			return -1;
		else
			return idx;
	}
};

//Count Inversions in array
int main()
{
	int n;
	cin >> n;
	pair<int, int> arr[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].f;
		arr[i].s = i;
	}

	BIT tree(n + 1);
	int aux[n];
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
	{
		aux[arr[i].second] = i + 1;
	}
	int invCount = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		invCount += tree.prefSum(aux[i] - 1);
		tree.update(aux[i], 1);
	}
	cout << invCount << endl;
}
