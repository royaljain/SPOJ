#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>
#define PI 3.141592653589

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int a,b,c;
		cin>>a>>b>>c;


		double x = (c*1.0)/a;

		//while(abs(a*x + b*sin(x*PI/180)-c) > 0.000000000001)
		for(int i=0;i<100;i++)
		{
			double f = a*x + b*sin(x) - c;
			double f_ = a + b*cos(x);
			x = x - f/f_;
		}
		
		printf("%.6f\n",x);
	}


}
