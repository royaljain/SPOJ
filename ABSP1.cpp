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
		long long int arr[n];

		for(int i=0;i<n;i++)
		cin>>arr[i];


		long long int sum = 0;
		long long int curr = 0;
		long long int diff = 0;		

		for(int i = n-2;i>=0;i--)
		{
			diff = arr[i+1]-arr[i];
			curr = curr + (n-1-i)*diff;
			sum += curr;
		}

		cout<<sum<<endl;


	}


}
