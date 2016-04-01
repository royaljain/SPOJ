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
		long long int n;
		cin>>n;
		n = n+1;

		char arr[5] =  {'m','a','n','k','u'};

		long long int x = 5;
		
		int pow = 0;		

		while(x < n)
		{
			x = x*5;
			pow++;	
		}
		

		x = x/5;


		while(x >=1)
		{
			cout<<arr[n/x];
			n = n%x;
			x = x/5;
		}

	}


}
