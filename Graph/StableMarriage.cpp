//Gale Shapely Algorithm For Stable Marriage and Admission Problem
#include <bits/stdc++.h>
using namespace std;
const int n = 4;

bool checkWprefer(int graph[2*n][n], int m, int m1, int w)
{
	for(int i = 0; i < n; i++)
	{
		if (graph[w][i] == m)
		return true;
		
		if (graph[w][i] == m1)
		return false;
	}
}

void stableMarriage(int graph[2*n][n])
{
	int wpartner[n];
	bool mfree[n];
	memset(wpartner, -1, sizeof(wpartner));
	memset(mfree, 0, sizeof(mfree));
	
	int freecount = n;
	while(freecount > 0)
	{
		int m;
		for(m = 0;m < n; m++)
		if (mfree[m] == false)
		break;
		
		for(int i = 0; i < n && mfree[m] == false; i++)
		{
			int w = graph[m][i];
			
			if (wpartner[w-n] == -1)
			{
				wpartner[w-n] = m;
				freecount--;
				mfree[m] = 1;
			}
			else
			{
				int m1 = wpartner[w-n];
				if (checkWprefer(graph, m, m1, w))
				{
					wpartner[w-n] = m;
					mfree[m] = 1;
					mfree[m1] = 0;
				}
			}
		}
	}
	
	cout << "Woman\tMan\n";
	for(int i = 0; i < n; i++)
	{
		cout << n+i << "\t" << wpartner[i] << endl;
	}
}

int main()
{
	
	int prefer[2*n][n] = { {7, 5, 6, 4}, 
        {5, 4, 6, 7}, 
        {4, 5, 6, 7}, 
        {4, 5, 6, 7}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
    }; 
    stableMarriage(prefer);
}
