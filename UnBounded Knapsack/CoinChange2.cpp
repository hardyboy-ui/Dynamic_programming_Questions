#include<bits/stdc++.h>
using namespace std;

int t[100][1000];
int coinChange2(int *coin,int n,int sum)
{
	for(int i=0;i<=sum;i++)
	{
		t[0][i]=INT_MAX;
	}
	
	for(int i=0;i<=n;i++)
	{
		t[i][0]=0;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(coin[i-1]<=j)
			{
				int x=t[i][j-coin[i-1]];
				int y=t[i-1][j];
				t[i][j]=min(x+1,y);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

/*int coinChange2(int *coin,int n,int sum)
{
	if(sum==0)
	{
		return 0;
	}
	if(n==0)
	{
		return INT_MAX;
	}
	
	if(coin[n-1]<=sum)
	{
		int x=coinChange2(coin,n,sum-coin[n-1]);
		int y=coinChange2(coin,n-1,sum);
		return min(x+1,y);
	}
	else
	{
		return coinChange2(coin,n-1,sum);
	}
}*/
int main()
{
	int n;
	cin>>n;
	
	int *coin=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	int sum;
	cin>>sum;
	
	int answer=coinChange2(coin,n,sum);
	cout<<answer<<endl;
	return 0;
}
