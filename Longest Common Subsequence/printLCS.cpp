#include<bits/stdc++.h>
using namespace std;

string printLCS(string s1,int n1,string s2,int n2)
{
	int t[n1+1][n2+1];
	string answer;
	
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
			if(s1[i-1]==s2[j-1])
			{
				t[i][j]=1+t[i-1][j-1];
			}
			else
			{
				t[i][j]=max(t[i-1][j],t[i][j-1]);
			}
		}
	}
//	cout<<t[n1][n2];
	
	
	int i=n1,j=n2;
	
	
	while(i>0&&j>0)
	{
		if(s1[i-1]==s2[j-1])
		{
			answer.push_back(s1[i-1]);
			i--;
			j--;
		}
		else
		{
			if(t[i-1][j]>=t[i][j-1])
			{
				i--;
			}
			else
			{
				j--;
			}
		}
	}
//	cout<<answer<<endl;
	reverse(answer.begin(),answer.end());
	return answer;
}
int main()
{
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	
	
	string answer=printLCS(s1,s1.length(),s2,s2.length());
	cout<<answer<<endl;
}
