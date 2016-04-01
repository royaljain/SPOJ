#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#define mod 5000000
using namespace std;

int getSum(int* tree,int index)
{
	int ans = 0;
	
	while(index > 0)
	{
		ans = (ans + tree[index])%mod;
		index = index - ((index)&(-index));	
	}
	
	return ans;
}

void update(int* tree,int index,int val,int n)
{
	val = val - tree[index];
	
	//cout<<index<<" "<<val<<endl;
	while(index <= n )
	{
		tree[index] = (tree[index] + val)%mod;
		index = index + ((index)&(-index));		
	}
	
}

int main()
{
	int n,k;
	cin>>n>>k;
	
	int arr[n+1];
	
	vector<int> V;
	
	for(int i=1;i<=n;i++)cin>>arr[i],V.push_back(arr[i]);
		
	sort(V.begin(),V.end());

	map<int,int> M;
	
	int  ctr = 1;
	
	for(int i=0;i<V.size();i++)
	{
		if(M.find(V[i]) == M.end())M[V[i]] = ctr,ctr++;			
	}

	for(int i=1;i<=n;i++)arr[i] = M[arr[i]];

	
	int tree[n+1];
	
	int dp[n+1][k+1];
	
	for(int i=1;i<=n;i++)dp[i][1] = 1;
	
	for(int i=0;i<=n;i++)tree[i] = 0;

	for(int i=2;i<=k;i++)
	{
		
		for(int j=1;j<=n;j++)
		{		
			dp[j][i] = getSum(tree,arr[j]-1);			
			update(tree,arr[j],dp[j][i-1],n);			
			
		}	
		
		for(int j=0;j<=n;j++)
		{
			tree[j]=0;
		}
		
	}	
	
	int out = 0;
	
	for(int i=1;i<=n;i++)
	{
		out = (out + dp[i][k])%mod;
	}	
	
	cout<<out<<endl;
}
