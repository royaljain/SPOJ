#include <iostream>
#include <string>

using namespace std;


int main()
{
	int t1;
	string t;
	getline(cin,t);
	t1 = stoi(t);

	while(t1--)
	{
		string blankline;
		getline(cin,blankline);
		string line;
		getline(cin,line);
		
		int pos = line.find(" + ");
		string a = line.substr(0,pos);
		line = line.substr(pos+3);
		pos = line.find(" = ");
		string b = line.substr(0,pos);
		string c = line.substr(pos+3);
		int a1,b1,c1;

		if (a.find("mac")!=string::npos)
		{
			b1 = stoi(b);
			c1 = stoi(c);
			a1 = c1 - b1;
		}
		else if(b.find("mac")!=string::npos)
		{
			a1 = stoi(a);
			c1 = stoi(c);
			b1 = c1 - a1;
		}
		else
		{
			a1  = stoi(a);
			b1 = stoi(b);
			c1 = a1 + b1;
		}		
		

		cout<<a1<<" + "<<b1<<" = "<<c1<<endl;
	}

	return 0;
}
