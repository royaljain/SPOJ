#include <iostream>
using namespace std;

int main()
{
	while(true)
	{
		int a,b,c;
		cin>>a>>b>>c;

		if(a==0 && b==0 && c==0)
		{
			break;
		}
		

		else if(2*b == a+c)
		{
			cout<<"AP "<<b+c-a<<endl;
		}

		else
		{
			cout<<"GP "<<(b*c)/a<<endl;
		}
	}	


}
