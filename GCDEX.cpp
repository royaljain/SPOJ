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
 
 
int main()
{
    
    pair<int,lint>* arr = new pair<int,lint>[MAX];	
	
	
	for(int i=1;i<MAX;i++)
	{
	    arr[i].first = 0;
	    arr[i].second = 0;
	}
	
	for(int i=1;i<MAX;i++)
	{
	    int j = 2;
	    int diff = i - arr[i].first;
	    
	    while(j*i < MAX)
	    {
	        arr[j*i].first += diff;
	        arr[j*i].second += (j-1)*diff;
	        j++;
	    }
	}
	
	lint sum = 0;
	
	for(int i=1;i<MAX;i++)
	{
		sum += arr[i].second;
		arr[i].second = sum;
	}
	
	int n;
	
	while((scanf("%d",&n) != EOF) && n != 0)
	{
	    printf("%lld\n",arr[n].second);
		
	}
			
    return 0;
}
