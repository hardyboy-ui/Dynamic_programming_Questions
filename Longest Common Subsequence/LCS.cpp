#include<bits/stdc++.h>
using namespace std;
int t[100][1000];


int LCS(string s1,int n1,string s2,int n2)
{
	for(int i=0;i<=n1;i++)
	{
		t[i][0]=0;
	}
	for(int i=0;i<=n2;i++)
	{
		t[0][i]=0;
	}
	
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[i-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else
			{
				t[i][j]=max(t[i-1][j],t[i][j-1]);
			}
		}
	}
	return t[n1][n2];
}
/*int LCS(string x,int n1,string y,int n2)
{
	if(n1==0||n2==0)
	{
		return 0;
	}
	if(t[n1][n2]!=-1)
	{
		return t[n1][n2];
	}
	if(x[n1-1]==y[n2-1])
	{
		t[n1][n2]=LCS(x,n1-1,y,n2-1)+1;
		return t[n1][n2];
	}
	else
	{
		t[n1][n2]=max(LCS(x,n1-1,y,n2),LCS(x,n1,y,n2-1));
		return t[n1][n2];
	}
}*/
/*int LCS(string x,int n1,string y,int n2)
{
	if(n1==0||n2==0)
	{
		return 0;
	}
	
	if(x[n1-1]==y[n2-1])
	{
		return LCS(x,n1-1,y,n2-1)+1;
	}
	else
	{
		return max(LCS(x,n1-1,y,n2),LCS(x,n1,y,n2-1));
	}
}*/
int main()
{
	string x;
	cin>>x;
	string y;
	cin>>y;
	memset(t,-1,sizeof(t));
	int answer=LCS(x,x.length(),y,y.length());
	cout<<answer<<endl;
}
