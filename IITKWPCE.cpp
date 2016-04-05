#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;






int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string s;
		cin>>s;
		
		int n = s.size();

		vector<vector<bool> > IsPalin(n+1,vector<bool>(n+1,false)) ;
		
		
		for(int i=1;i<=n;i++)IsPalin[i][i]=  true;
		
		for(int k=1;k<n;k++)
		{
			for(int i=1;i<=(n-k);i++)
			{
				if(s[i-1] == s[i+k-1])
				{
					if( k == 1 || ((k > 1) && IsPalin[i+1][i+k-1]))
					{
						IsPalin[i][i+k] = true;
					}	
					else
					{
						IsPalin[i][i+k] = false;
					}
				}
				else
				{
					IsPalin[i][i+k] = false;	
				}	
			}	
		}
		
		
		vector<int> DP(n+1,0);
		
		for(int i=1;i<=n;i++)
		{
			int mi = 10000;
			
			for(int j=1;j<=i;j++)
			{	
				if(IsPalin[j][i])
				{
					mi = min(mi,DP[j-1] + 1);	
				}		
			}	
			
			DP[i] = mi;
		}
	
		cout<<DP[n]<<"\n";

	}


}
