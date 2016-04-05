#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;


int power[10] =  {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

vector<int> count(int a)
{
		vector<int> V(10,0);
		
		int c = a;
	
		for(int i=0;i<10;i++)
		{
			int sum = 0;
			int curr = 0;


			for(int j = 9;j>=0;j--)
			{
				if(i != 0)sum += curr*power[j];
				else sum += max(0,(curr-1)*power[j]);
				
				int d = a/power[j];		
				
				if( ((curr != 0) || (i != 0)) && i < d ) sum += power[j]; 
				else if( ((curr != 0) || (i != 0)) && i == d) sum += (1+a%power[j]);

				curr = curr*10 + d;
				a = a%power[j];
			}
					
			a = c;
			V[i] = sum;
		}
		
		return V;
}


int main()
{
	int a,b;
	cin>>a>>b;

	while(a)
	{

		if( b < a)
		{
			int t = b;
			b = a;
			a = t;	
		}
	
		vector<int> B = count(b);
		vector<int> A = count(a-1);
	
		for(int i=0;i<10;i++)
		{
			cout<<B[i]-A[i]<<" ";	
		}
	
		cout<<"\n";
	
		cin>>a>>b;
	}


}
