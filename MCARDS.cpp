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
#define MAX 101
using namespace std; 
 
typedef pair<int,int> PII;



int longestIncreasing(PII* arr,int* perm,int n)
{
    int a[n] ;
    
    
    for(int i=0;i<n;i++)
    {
        a[i] =  perm[arr[i].first]*MAX + arr[i].second;
    }
    
    
    
    int dp[n];
    
    dp[0] = 1;
    int ans = 1;
    
    for(int i=1;i<n;i++)
    {
        int temp = 0;
        
        for(int j=0;j<i;j++)
        {
            if(a[i] > a[j])
            {
                temp = max(temp,dp[j]);        
            }
        }  
        
        dp[i] = temp + 1;
        int t = dp[i];
        ans = max(ans,t);
    }
    
    return ans;
}

int ma = 0;

void allperm(PII* arr,int* perm,int c,int i,int n)
{
    if(i==c)
    {
        int t = longestIncreasing(arr,perm,n);
        ma = max(ma,t);
    }
    else
    {
        for(int j = i;j <=c;j++)
        {
            swap(perm[i],perm[j]);
            allperm(arr,perm,c,i+1,n);
            swap(perm[i],perm[j]);
        }
    }
}

 
 
int main()
{
	
	
	int c,n;
	cin>>c>>n;
	
	int N = c*n;
	
	PII arr[N];
	
	for(int i = 0;i < N;i++)
	{
	    cin>>arr[i].first;
	    cin>>arr[i].second;
	}
	
	int perm[c+1];

	for(int i = 1;i <= c;i++)
	{
        perm[i] = i;
	}	
	
	allperm(arr,perm,c,1,N);
	
	cout<<(N-ma)<<endl;
			
    return 0;
}
