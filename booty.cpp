#include <bits/stdc++.h>
using namespace std;

int main()
{
	for (int i = 0; i<7 ; i++)
	for (int j = 1; j <=7; j++)
	{
		if(j >7-i && j<=7)
		cout << "  ";
		else
		cout << j << " ";
		if (j == 7)
		for (int k = 6 ; k >=1; k--)
		{
			if (k>7-i )
			cout << "  ";
			else
			cout << k << " ";
			if (k ==1)
			cout << endl;
		}
	}
	return 0;
}
