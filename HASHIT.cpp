#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;


struct hashTable
{
	bool empty[101];
	char* arr[101];



	hashTable()
	{
		for(int i=0;i<101;i++)
		{
			arr[i] = 0;
			empty[i]=true;
		}
	}


	void insert(char* c)
	{
		int hash = hashCal(c);
//		cout<<hash<<" "<<c<<endl;	
		int j=0;
		for(;j<=19;j++)
		{
			int pos = (hash + j*j + 23*j)%101;

			if(!empty[pos] && (strcmp(arr[pos],c)==0))
			{
//				cout<<"W "<<j<<endl;
				break;
			}		

			if(j==19)
			{
				for(j=0;j<=19;j++)
				{
					int pos = (hash + j*j + 23*j)%101;
					
					if(empty[pos]) 
					{

//						cout<<"I "<<pos<<endl;
						arr[pos] = c;
						empty[pos] = false;
						break;
					}
				}
				
				j=19;
			}	
		}
		
	}

	void del(char* c)
	{

		int hash = hashCal(c);
		
		int j=0;
		for(;j<=19;j++)
		{
			int pos = (hash + j*j + 23*j)%101;

			if(!empty[pos] && (strcmp(arr[pos],c)==0))
			{
				arr[pos] = 0;
				empty[pos] = true;
				break;
			}		

		}

	}


	int hashCal(char* c)
	{

		int n = strlen(c);

//		cout<<"H "<<n<<endl;

 		int sum = 0;

		for(int i=0;i<n;i++)
		{
			sum += (i+1)*c[i];
		}
	
		sum *= 19;
		
		return sum%101;
	}


	void print()
	{
		
		int count = 0;
		for(int i=0;i<101;i++)
		{
			if(!empty[i])count++;

		}
		
		cout<<count<<endl;

		for(int i=0;i<101;i++)
		{
			if(!empty[i])cout<<i<<":"<<arr[i]<<endl;

		}

	}

};






int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		int n;
		cin>>n;


		hashTable H;

			
		char c[n][25];

		for(int i=0;i<n;i++)
		{
			cin>>c[i];
			if(c[i][0]=='A')
			H.insert(c[i]+4);
			else
			H.del(c[i]+4);
		}
		
		H.print();
	}


}
