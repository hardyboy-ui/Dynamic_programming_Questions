//#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int t[100][1000];
//iterative solution
int knapsack(int *wt,int *val,int n,int w)
{
	//initialize the t array!
	for(int i=0;i<=w;i++)
	{
		t[0][i]=0;
	}
	
	for(int i=0;i<=n;i++)
	{
		t[i][0]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++)
		{
			if(wt[i-1]<=w)
			{
				t[i][j]=max(val[i-1]+t[i-1][j-wt[i-1]],t[i-1][j]);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][w];
}
/*int knapsack(int *wt,int *val,int n,int w)
{
	if(t[n][w]!=-1)
	{
		return t[n][w];
	}
	if(n==0||w==0)
	{
		return 0;
	}
	
	if(wt[n-1]<=w)
	{
		int x=knapsack(wt,val,n-1,w-wt[n-1]);
		int y=knapsack(wt,val,n-1,w);
		t[n][w]=max(x+val[n-1],y);
		return t[n][w];
	}
	else
	{
		t[n][w]=knapsack(wt,val,n-1,w);
		return t[n][w];
	}
}*/

//                   RECURSIVE SOLUTION
/*int knapsack(int *wt,int *val,int n,int w)
{
	if(n==0||w==0)
	{
		return 0;
	}
	
	if(wt[n-1]<=w)
	{
		int x=knapsack(wt,val,n-1,w-wt[n-1]);
		int y=knapsack(wt,val,n-1,w);
		return max(x+val[n-1],y);
	}
	else
	{
		return knapsack(wt,val,n-1,w);
	}
}*/

int main()
{
	memset(t,-1,sizeof(t));
	int n;
	cin>>n;
	int *wt=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>wt[i];
	}
	int *val=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>val[i];
	}
	int w;
	cin>>w;
	int answer=knapsack(wt,val,n,w);
	cout<<answer;
	return 0;
}
