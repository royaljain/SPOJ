#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int n;
	cin>>n;

	int i = 1 ;
	int sqr = sqrt(n);
	
	int sum = 0;

	while( i <= sqr)
	{
		sum += (n/i - (i-1));
		i++;
	}

	cout<<sum<<endl;

}
