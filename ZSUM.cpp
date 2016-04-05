#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>
#define MOD 10000007
#define lint long long int
using namespace std;



lint ans(lint n,lint p)
{
	if( p  == 0)return 1;
	if( p  == 1)return n;	
	else
	{
		if( p%2 == 0)
		{
			lint r = ans(n,p/2);
			return (r*r)%MOD;
		}	
		else
		{
			lint r = ans(n,p/2);
			return (((r*r)%MOD)*n)%MOD;
		}
	}
}



int main()
{
	lint n,k;
	cin>>n>>k;

	
	while(n != 0)
	{
		lint A = ((((ans(n,k) + 2* ans(n-1,k))%MOD) + ((ans(n,n) + 2*ans(n-1,n-1))%MOD))%MOD);
		cout<<A<<"\n";
		cin>>n>>k;
	}


}
