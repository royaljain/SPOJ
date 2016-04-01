#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>
#define MAX 40000001
#define M 5000001
using namespace std;

int main()
{

	int* arr = new int[M];
	bool* present = new bool[MAX];

	for(int i=0;i<MAX;i++)present[i]=false;

	present[0] = true;
	arr[0] = 0;

	for(int i=1;i<M;i++)
	{
		int v = arr[i-1] - i;

		if(v <= 0 || present[v])
		{
			arr[i] = arr[i-1]+i;
		}	
		else
		{
			arr[i] = v;
		}

		//cout<<arr[i]<<endl;

		present[arr[i]] = true;

		//if(i < 100)cout<<arr[i]<<endl; 
	}



	int t;
	cin>>t;



	while( t != -1)
	{
		cout<<arr[t]<<"\n";
		cin>>t;
	}


}
