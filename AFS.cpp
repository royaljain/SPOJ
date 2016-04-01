#include <iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;
	
		long long int sum = 0;

		for(int i=1;i<n;i++)
		{
			sum += (n/i -1)*i;	
		}
	
		cout<<sum<<endl;

	}
}
