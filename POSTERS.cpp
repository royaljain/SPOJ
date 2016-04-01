#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>
#define max 40000
using namespace std;



bool visible[max];

struct node
{
	int t;
	int l,r;
	node* left;
	node* right;

	node(int ti,int le,int ri)
	{
		t = ti;
		l = le;
		r = ri;
		left=right=0;
	}
};



struct tree
{
	node* root;

	tree()
	{
		root = 0;
	}

	void insert(int t,int start,int end)
	{
		root = inserth(root,t,start,end);
	}


	node* inserth(node* curr,int t,int start,int end)
	{
		if(curr==0)
		{
			return new node(t,start,end);
		}
		else
		{
			if(curr->l > end)
			{
				curr->left =  inserth(curr->left,t,start,end);
				return curr;
			}
		
			else if(curr->r < start)
			{	
				curr->right =  inserth(curr->right,t,start,end);
				return curr;
			}

			else
			{
				if(start > curr->l && end < curr->r)
				{
					node* temp1 = new node(t,start,end);
					node* temp2 = new node(curr->t,curr->l,start-1);
					node* temp3 = new node(curr->t,end+1,curr->r);
					
					temp2->left = curr->left;
					temp3->right = curr->right;
			
					temp1->left  = temp2;
					temp1->right = temp3;
			
					return temp1;

				}
			
				else if( start <= curr->l && end >= curr->r)
				{
					curr->t =t;
					curr->l = start;
					curr->r = end;
					
					curr->left = leftTree(curr->left,start);
					curr->right = rightTree(curr->right,end);
				
					return curr;
				}
		
				else if ( start < curr->l)
				{
					node* temp = new node(t,start,end);

					curr->l = end+1;
					
					temp->left = leftTree(curr->left,start);
					curr->left = 0;
					temp->right = curr;
				
					return temp;

				}
	
				else
				{

					node* temp = new node(t,start,end);

					curr->r = start-1;
					
					temp->right = rightTree(curr->right,end);
					curr->right = 0;
					temp->left = curr;
				
					return temp;


				}
			}

		}

	}


	node* leftTree(node* curr,int lim)
	{
		if(curr==0)return 0;
	
		else if(curr->l >= lim)
		{
			return leftTree(curr->left,lim);
		}
		
		else if(curr->r < lim)
		{
			curr->right = leftTree(curr->right,lim);
			return curr;
		}
		else
		{
			curr->r = lim-1;
			curr->right = 0;
			return curr;
		}
	}

	node* rightTree(node* curr,int lim)
	{
		if(curr==0)return 0;
	
		else if(curr->r <= lim)
		{
			return rightTree(curr->right,lim);
		}
		
		else if(curr->l > lim)
		{
			curr->left = rightTree(curr->left,lim);
			return curr;
		}
		else
		{
			curr->l = lim+1;
			curr->left = 0;
			return curr;
		}
	}


	void traverse(node* curr)
	{
		if(curr==0);
		else
		{
			visible[curr->t] = true;
			traverse(curr->left);
			traverse(curr->right);
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

		tree t;

		for(int i=0;i<max;i++)
		{	
			visible[i] = false;
		}
		

		int l,r;
		
		for(int i=0;i<n;i++)
		{
			cin>>l>>r;

			t.insert(i,l,r);
		}

		t.traverse(t.root);
	
		int count = 0 ;
	
		for(int i=0;i<max;i++)
		{
			if(visible[i])count++;
		}
		
		cout<<count<<endl;
	}


}
