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
	int N;
	cin>>N;

	while(N--)
	{
		int x,y;
		cin>>x>>y;
		
		if(x == y) 
		{
			if(x %2 == 0)cout<<2*x<<endl;
			else cout<<2*x -1<<endl;				
		}
		else if(x == y+2)
		{
			if(y %2 == 0)cout<<2*y+2<<endl;
			else cout<<2*y+1<<endl;
		}
		else
		{
				cout<<"No Number"<<endl;
		}	
	}


}
