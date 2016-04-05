#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>
#define INF 100000000
using namespace std;


struct node
{
	int label;
	int weight;


	node(int a,int b){label = a;weight = b;}

	

};

struct LessT
{
	bool operator()(const node& lhs, const node& rhs)const
	{
		if(lhs.weight != rhs.weight) return lhs.weight > rhs.weight;
		return lhs.label > rhs.label;
	}

};


int dist(int S,int T)
{
	int a = S%8;
	int b = S/8;
	
	int c = T%8;
	int d = T/8;

	return a*c + b*d;
}


int djikstra(vector<int> *graph,int s,int t)
{
	priority_queue<node,vector<node>,LessT> Q;
	
	for(int i=0;i<64;i++)
	{
		if(i==s) Q.push(node(s,0));
		else Q.push(node(i,INF));
	}
	
	vector<int> Dis(64,INF);
	
	Dis[s] = 0;
	
	while(!Q.empty())
	{
		node n = Q.top();
		Q.pop();
		
		
		
			
		int l = n.label;
		
		int w = n.weight;
		
		
		if( l == t ) return w;
		
		
		for(int i=0;i<graph[l].size();i++)
		{
			
			int ti = graph[l][i];
			
			
			if(	Dis[l] + dist(l,ti) < Dis[ti])
			{
				Dis[ti] = Dis[l] + dist(l,ti);
				Q.push(node(ti,Dis[ti]));
			} 
		}
		
	}
	
}


vector<int> neighbours(int i,int j)
{
	vector<int> V;
	
	if(i - 2 >=0 && j - 1 >= 0)
	{
			V.push_back((i-2) + 8*(j-1));
	}
	if(i - 2 >=0 && j + 1 < 8)
	{
			V.push_back((i-2) + 8*(j+1));
	}
	if(i + 2 < 8 && j - 1 >= 0)
	{
			V.push_back((i+2) + 8*(j-1));
	}
	if(i + 2 < 8 && j + 1 < 8)
	{
			V.push_back((i+2) + 8*(j+1));
	}	
	if(j - 2 >=0 && i - 1 >= 0)
	{
			V.push_back((i-1) + 8*(j-2));
	}
	if(j - 2 >=0 && i + 1 < 8)
	{
			V.push_back((i+1) + 8*(j-2));
	}
	if(j + 2 < 8 && i - 1 >= 0)
	{
			V.push_back((i-1) + 8*(j+2));
	}
	if(j + 2 < 8 && i + 1 < 8)
	{
			V.push_back((i+1) + 8*(j+2));
	}
	
	
	return V;
}


int main()
{
	
	
	vector<int> graph[64];
	
		
	for(int i=0;i<64;i++)
	{
		graph[i] = neighbours(i%8,i/8);		
	}
	

	
	
	int a,b,c,d;
	

	while(cin>>a>>b>>c>>d)
	{
		if( a > 7 || b > 7 || c > 7 || d > 7 || a < 0 || b < 0 || c < 0 || d < 0 )cout<<-1<<"\n";
		else
		{
			cout<<djikstra(graph,a+b*8,c+d*8)<<"\n";
		}

	}
}
