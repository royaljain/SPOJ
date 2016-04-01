#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;


struct segTree
{
	int* arr;
	int size;

	int* out;

	int getsize(int n)
	{
		int x = 1;
		
		while(x < n)
		{
			x = x*2;
		}

		return 2*x;
	}


	segTree(int n)
	{
		size =  n;
		arr = new int[getsize(n)];
		out = new int[n+1];

		build(1,1,getsize(n)/2);

//		cout<<"O"<<endl;

		int k = 0;

		for(int i=1;i<n;i++)
		{
//			cout<<"I "<<i<<endl;
	
			int before = getfree(1,1,k-1,1,getsize(n)/2);	
			int after = getfree(1,k+1,size,1,getsize(n)/2);
		
			int add = i%(before+after);

//			cout<<"A B AF "<<add<<" "<<before<<" "<<after<<endl;

			if(add >= after)
			{
				k = insert(1,add - after,1,getsize(n)/2);
			}
  			
			else
			{
				k = insert(1,before + add,1,getsize(n)/2);
			}

//			cout<<"K "<<k<<endl;

			k = k - (getsize(n)/2);
			k += 1;
			
			out[k] = i ;			

		}

		print();

	}


	int getfree(int i,int a,int b,int start,int end)
	{
//		cout<<"##### "<<a<<" "<<b<<endl;
		if(b<a)return 0;
		
		else if(start==end)
		{
			return arr[i];
		}

		else
		{
		
		
			int mid = (start+end)/2;

			if(b <= mid)
			{
				return getfree(2*i,a,b,start,mid);
			}
	
			else if( a> mid)
			{
				return getfree(2*i+1,a,b,mid+1,end);
			}
	
			else
			{
				return getfree(2*i,a,mid,start,mid) + getfree(2*i+1,mid+1,b,mid+1,end);
			}
		}
		
	}

	int insert(int i,int a,int start,int end)
	{	
		if(start==end)
		{
			arr[i] = 0;
			return i;
		}
		else
		{
			int mid = (start+end)/2;
			
			if(arr[2*i] > a)
			{
				int temp = insert(2*i,a,start,mid);
				arr[i] = arr[2*i]+arr[2*i+1];
				return temp;
			}

			else
			{
				int temp = insert(2*i+1,a-arr[2*i],mid+1,end);
				arr[i] = arr[2*i]+arr[2*i+1];
				return temp;
			}
		}

	}


	void build(int i,int start,int end)
	{
		if(start==end)
		{
			arr[i] = 1; 
		}


		else
		{
			int mid = (start+end)/2;
	
			build(2*i,start,mid);
			build(2*i+1,mid+1,end);

			arr[i] = arr[2*i]+arr[2*i+1];
		}

	}


	void print()
	{
		for(int i=1;i<=size;i++)
		{
			if(out[i]==0)printf("%d ",size);
			else printf("%d ",out[i]);
		}

		printf("\n");

	}






};










int main()
{
	int t;
	scanf("%d",&t);

	while(t--)
	{
		int n;
		scanf("%d",&n);


		segTree t(n);


	}


}
