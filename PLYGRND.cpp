#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;




bool solve(vector<double> &V)
{
	
		sort(V.begin(),V.end());
		
		double sum = 0;
		
		for(int i=0;i<V.size();i++)
		{
			if(V[i] <= sum) return true;
			sum += V[i];
		}
		
		return false;
		
}




int main()
{
	int n;
	cin>>n;

	while(n != 0)
	{
		vector<double> V(n,0);
		
		for(int i=0;i<n;i++)cin>>V[i];
			
	
		if(solve(V))cout<<"YES\n";
		else cout<<"NO\n";
	
	
		cin>>n;
		
	}

	
}
