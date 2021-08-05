#include <iostream>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		int sum = 0;
		cin >> n;
		int arr[n];
		for (int i = 0; i < n; i++)
		cin >> arr[i];
		for (int k = 0; k < n; k++)
		sum +=arr[k];
		if ((sum - 100)>=0 && (sum-100)<n)
		cout << "YES\n";
		else if((sum - 100)>=0 && (sum-100)>n)
		cout << "NO\n";
		else if((sum - 100)<0 && (100-sum)<n)
		cout << "YES\n";
		else if((sum - 100)<0 && (100-sum)>n)
		cout << "NO\n";
	}
	return 0;
}
