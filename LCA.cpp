#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <utility>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <map>
#include <list>
#define lint long long int
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
#define MAX 1000001
using namespace std; 

void buildTable(int** P,int n,int* parent)
{
	int log = 1;
	
	for(;1<<log <= n ;log++);
	
	
	for(int j = 0;j<log;j++)
	{
		for(int i=1;i<=n;i++)
		{
			P[i][j] = -1 ; 
		}	
	}
	
	for(int i=1;i<=n;i++)P[i][0] = parent[i];
	
	
	
	for(int j = 1;j<log;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(P[i][j-1] != -1)
			{
				P[i][j] = P[P[i][j-1]][j-1]; 
				//cout<<i<<" "<<j<<" "<<P[i][j]<<endl;
			}
		}	
	}
} 
 
int findLCA(int** P,int* parent,int n,int u,int v,int* L)
{
	if(L[u] < L[v])
	{
		u = u + v;
		v = u - v;
		u = u - v;	
	}
	
	
	int log ;
	
	for (log = 1; 1 << log <= L[u]; log++);
    log--;
	
	
	for(int i=log;i>=0;i--)
	{
		if(L[P[u][i]] >= L[v]) u = P[u][i];	
	}
	
	
	if(u==v)return u;
	//cout<<L[u]<<" "<<L[v]<<endl;
	
	
	for(int i=log;i>=0;i--)
	{
		if(P[u][i] != -1 && P[v][i] != P[u][i])u = P[u][i],v = P[v][i];
	}
	
	return parent[u];
} 
 
 
void dfs(list<int>* tree,int i,int* L,int curr)
{
	L[i] = curr;
	list<int>::iterator it = tree[i].begin();
	
	while(it != tree[i].end())
	{
		dfs(tree,*it,L,curr+1);
		it++;
	}	
	
}

 
int main()
{
	int t;
	scanf("%d",&t);
	
	int ctr = 1;
	while(ctr <=t)	
	{	
		int n;
		scanf("%d",&n);
		
		int m,node;
		
		int parent[n+1];
		int level[n+1];
		list<int> tree[n+1];
		
		for(int i=0;i<=n;i++)parent[i]=-1;
		
		
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			
			for(int j = 0 ;j<m;j++)	
			{
				scanf("%d",&node);
				parent[node] = i;
				tree[i].push_back(node);	
			}	
		}	
		
		int i=1;
		for(;i<=n;i++)if(parent[i]==-1)break;
		
		dfs(tree,i,level,1);
		
		int log = 1;
		
		for(;1<<log <= n ;log++);
		
		
		int** P;
		
		P = new int*[n+1];
		
		for(int j=0;j<=n;j++)
		{
			P[j] = new int[log];
		}	
		
		buildTable(P,n,parent);
		
		//cout<<P[5][2];	
		
		int q;
		scanf("%d",&q);
		
		printf("Case %d:\n",ctr);
		
		int u,v;
		
		for(int j=0;j<q;j++)
		{
			scanf("%d %d",&u,&v);
			printf("%d\n",findLCA(P,parent,n,u,v,level));
		}
		
		ctr++;
	}			
   
   
    return 0;
}
