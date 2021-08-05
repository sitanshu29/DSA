//Egyptian Fraction
#include <bits/stdc++.h>
using namespace std;
#define ll long long
void printEgypt(ll nr, ll dr)
{
	if (nr == 0 || dr == 0)
	{
		cout << endl;
		return ;
	}
	
	if (dr%nr == 0)
	{
		cout << "1/" << dr/nr << endl;
		return ;
	}
	
	if (nr > dr)
	{
		cout << nr/dr << " + ";
		printEgypt(nr%dr, dr); 
	}
	else
	{
		ll x = dr/nr +1;
		cout << "1/" << x << " + ";
		printEgypt(nr*x - dr, dr*x);
	}
	
}

int main()
{
	int t;
	cin >> t;
	while(t--){
		
	
	ll nr, dr; char x;
	cin >> nr >>x >> dr;
	printEgypt(nr, dr);
	
}
return 0;}
