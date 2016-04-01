#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <list>
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;

int main()
{

	while(true)
	{
		int h,w;
		cin>>w>>h;
		
		if(h==0 && w==0)break;
		
		
		char shop[h+1][w+1];
		int time[h+1][w+1];

		int si,sj,di,dj;
	

		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				time[i][j] = -1;
				cin>>shop[i][j];
		
				if(shop[i][j] == 'S')
				{
					si = i;
					sj = j;
				}
				if(shop[i][j] == 'D')
				{
					di =  i;
					dj = j;
				}

			}
		}




		time[di][dj] = 0;

		queue<pair<int,int> > Q;

		pair<int,int> p(di,dj);
		
		Q.push(p);

		while(!Q.empty())
		{
			pair<int,int> p1 = Q.front();Q.pop();
			
			int fir = p1.first;
			int sec = p1.second;

			if(fir < h && (shop[fir+1][sec]-'0') >=0 && (shop[fir+1][sec] -'0') <= 9) 
			{
				if(time[fir+1][sec] == -1)
				{
					pair<int,int> temp(fir+1,sec);
					Q.push(temp);
					time[fir+1][sec] =  time[fir][sec] + (shop[fir+1][sec] - '0');
				}
				else
				{
					time[fir+1][sec] =  min(time[fir+1][sec],time[fir][sec] + (shop[fir+1][sec] - '0'));
				}
			}
	
			if(fir > 1 && (shop[fir-1][sec]-'0') >=0 && (shop[fir-1][sec] -'0') <= 9) 
			{
				if(time[fir-1][sec] == -1)
				{
					pair<int,int> temp(fir-1,sec);
					Q.push(temp);
					time[fir-1][sec] =  time[fir][sec] + (shop[fir-1][sec] - '0');
				}
				else
				{
					time[fir-1][sec] =  min(time[fir-1][sec],time[fir][sec] + (shop[fir-1][sec] - '0'));
				}
			}
			if(sec < w && (shop[fir][sec+1]-'0') >=0 && (shop[fir][sec+1] -'0') <= 9) 
			{
				if(time[fir][sec+1] == -1)
				{
					pair<int,int> temp(fir,sec+1);
					Q.push(temp);
					time[fir][sec+1] =  time[fir][sec] + (shop[fir][sec+1] - '0');
				}
				else
				{
					time[fir][sec+1] =  min(time[fir][sec+1],time[fir][sec] + (shop[fir][sec+1] - '0'));
				}
			}
			if(sec > 1  && (shop[fir][sec-1]-'0') >=0 && (shop[fir][sec-1] -'0') <= 9) 
			{
				if(time[fir][sec-1] == -1)
				{
					pair<int,int> temp(fir,sec-1);
					Q.push(temp);
					time[fir][sec-1] =  time[fir][sec] + (shop[fir][sec-1] - '0');
				}
				else
				{
					time[fir][sec-1] =  min(time[fir][sec-1],time[fir][sec] + (shop[fir][sec-1] - '0'));
				}
			}
		}

		int ti = 1000000;

		if(si < h && time[si+1][sj] < ti && time[si+1][sj] != -1) ti = time[si+1][sj];
		if(si > 1 && time[si-1][sj] < ti && time[si-1][sj] != -1) ti = time[si-1][sj];
		if(sj < w && time[si][sj+1] < ti && time[si][sj+1] != -1) ti = time[si][sj+1];
		if(sj > 1 && time[si][sj-1] < ti && time[si][sj-1] != -1) ti = time[si][sj-1];


		cout<<ti<<endl;
	}


}
