#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>
#define MAXN 101
#define MAXK 6
using namespace std;



int dp[MAXN][MAXN][MAXK];



int solve(vector<int> V,int K)
{
	int N = V.size()-1;
	
	for(int j=1;j<=N;j++)
	{
		for(int i=1;i<=j;i++)
		{
			for(int k=1;k<=K;k++)
			{
				if(i == j)
				{
					dp[i][j][k] = K-k;	
				}
				
				/*
				else if( k == K)
				{
					dp[i][j][k] = dp[i][j-1][K];
				}
				*/
				
				else 
				{
					
					int m = dp[i][j-1][1] + K-k;
					
					for(int l = j-1;l>=i;l--)
					{
						if(V[l] == V[j])
						{
							m = min(m,dp[i][l][min(k+1,K)] + dp[l+1][j-1][1]);
						}
					}	
					
					
					dp[i][j][k] = m;
				}
				
			}	
			
		}
	}		
		
	
	
	return dp[1][N][1];
	
}




int main()
{
	int N,K;
	cin>>N>>K;


	for(int i=0;i<MAXN;i++)
	{
		for(int j=0;j<MAXN;j++)
		{
			for(int k=0;k<MAXK;k++)dp[i][j][k] = 0;
		}
	}

	vector<int> V(N+1,0);

	for(int i=1;i<=N;i++)
	{
		cin>>V[i];
	}

	
	cout<<solve(V,K)<<endl;
}
