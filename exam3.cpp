#include <iostream>
using namespace std;
int main ()
{
	float h,m,i,j,k;
	cout<<"enter time\n";
	cin>>h>>m;
	i=h*60;
	j=(m*6)/12;
	k=i*.5-m*6+j;
	if(k>0)
	{cout<<"angle is "<<k<<endl;
	}
	else
	cout<<"angle is "<<-k<<endl;
	return 0;
}
