#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stack>

using namespace std;

int main()
{
	while(true)
	{
		
		int n;
		cin>>n;

		if(n==0)break;

		queue<int> Q; 

		
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			Q.push(a);
		}


		int curr = 1;

		stack<int> S;

		bool poss = true;

		while(!Q.empty())
		{
			int qTop = Q.front();
			
			if(qTop == curr)
			{
				Q.pop();
				curr++;
			}


			else if(!S.empty())
			{
				int sTop = S.top();
				
				if(sTop == curr)
				{
					S.pop();
					curr++;
				}

				else if ( sTop < qTop)
				{
					poss = false;
					break;
				}
				
				else
				{
					Q.pop();
					S.push(qTop);

				}

			}
		
			else
			{
				Q.pop();	
				S.push(qTop);
			}	
		}


		if(poss)cout<<"yes"<<endl;
		else cout<<"no"<<endl;

	}
}
