#include <iostream>
using namespace std;

int rev(int a)
{
	int out = 0;
	
	while(a!=0)
	{	
		out *= 10;
		out += a%10;
		a = a/10;

	}

	return out;
} 


int main()
{
	int N;
	cin>>N;

	while(N--)
	{
		int a,b;
		cin>>a>>b;
		cout<<rev(rev(a)+rev(b))<<endl;
	}


}
