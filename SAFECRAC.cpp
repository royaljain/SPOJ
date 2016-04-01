#include <iostream>
#define mod 1000000007
#define n 100000
using namespace std;

int main()
{
	int t;
	cin>>t;
	


	long long int arr[10][n];

	for(int i=0;i<10;i++)
	{
		arr[i][0]=1;
	}
	for(int i=1;i<n;i++)
	{
		arr[0][i] = arr[7][i-1];
		arr[1][i] = (arr[2][i-1] + arr[4][i-1])%mod;
		arr[2][i] = (arr[1][i-1] + arr[3][i-1]) + arr[5][i-1]%mod;
		arr[3][i] = (arr[2][i-1] + arr[6][i-1])%mod;
		arr[4][i] = (arr[1][i-1] + arr[5][i-1] + arr[7][i-1])%mod;
		arr[5][i] = (arr[2][i-1] + arr[4][i-1] + arr[6][i-1] + arr[8][i-1])%mod;
		arr[6][i] = (arr[3][i-1] + arr[5][i-1] + arr[9][i-1]%mod);
		arr[7][i] = (arr[0][i-1] + arr[4][i-1] + arr[8][i-1]%mod);
		arr[8][i] = (arr[5][i-1] + arr[7][i-1] + arr[9][i-1]%mod);
		arr[9][i] = (arr[6][i-1] + arr[8][i-1])%mod;

	}

	


	while(t--)
	{
		int q;
		cin>>q;
		long long int sum = 0;
		for(int i=0;i<10;i++)
		sum = (sum + arr[i][q-1])%mod;

		cout<<sum<<endl; 
	}




}
