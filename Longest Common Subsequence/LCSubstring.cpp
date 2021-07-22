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
	
	int max=0;
	for(int i=1;i<=n1;i++)
	{
		for(int j=1;j<=n2;j++)
		{
			if(s1[i-1]==s2[i-1])
			{
				t[i][j]=1+t[i-1][j-1];
				if(t[i][j]>max)
				{
					max=t[i][j];
				}
			}
			else
			{
				t[i][j]=0;
			}
		}
	}
	return max;
}
int main()
{
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	
	int answer=LCS(s1,s1.length(),s2,s2.length());
	cout<<answer<<endl;
	return 0;
}
