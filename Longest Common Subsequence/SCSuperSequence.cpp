#include<bits/stdc++.h>
using namespace std;

string SCSuperSequence(string s1,int n1,string s2,int n2)
{
	string answer="";
	int t[n1][n2];
	
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
				answer.push_back(s1[i-1]);
				i--;
			}
			else
			{
				answer.push_back(s2[j-1]);
				j--;
			}
		}
	}
	while(i>0)
	{
		answer.push_back(s1[i-1]);
		i--;
	}
	while(j>0)
	{
		answer.push_back(s2[j-1]);
		j--;
	}
	reverse(answer.begin(),answer.end());
	return answer;
}
int main()
{
	string s1;
	cin>>s1;
	string s2;
	cin>>s2;
	
	string answer=SCSuperSequence(s1,s1.length(),s2,s2.length());
	cout<<answer<<endl;
}
