#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>

using namespace std;

int main()
{
	int t;
	cin>>t;

	while(t--)
	{
		string exp;
		cin>>exp;
		
		stack<char> op;
		queue<char> out;
		
		
		for(int i=0;i<exp.size();i++)
		{
			if(exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/' || exp[i] == '^' || exp[i] == '(' ) 	
			{
					op.push(exp[i]);
			}	
			else if(exp[i] == ')')
			{
				out.push(op.top());
				op.pop();
				op.pop();	
			}
			else
			{
				out.push(exp[i]);	
			}
		}
		
		
		while(!out.empty())
		{
			cout<<out.front();
			out.pop();	
		}
		
		cout<<endl;
	}


}
