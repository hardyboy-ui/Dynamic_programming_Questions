#include<bits/stdc++.h>
using namespace std;
//find maximum number of ways

int t[100][1000];
int coinChange1(int* coin,int n,int sum)
{
	for(int i=0;i<=n;i++)
	{
		t[i][0]=1;
	}
	for(int i=0;i<=sum;i++)
	{
		t[0][i]=0;
	}
	t[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(coin[i-1]<=j)
			{
			    int x=t[i][j-coin[i-1]];
			    int y=t[i-1][j];
			    t[i][j]=x+y;
		    }
		    else
		    {
		    	t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][sum];
}

/*int coinChange1(int *coin,int n,int sum)
{
	if(sum==0)
	{
		return 1;
	}
	if(n==0)
	{
		return 0;
	}
	
	if(coin[n-1]<=sum)
	{
		int x=coinChange1(coin,n,sum-coin[n-1]);    //when we are considering the last element of the coin array .Since it is possible to consider this element again therefore calling on n
		int y=coinChange1(coin,n-1,sum);
		return x+y;
	}
	else
	{
		return coinChange1(coin,n-1,sum);
	}
}*/

int main()
{
	int n;
	cin>>n;
	int* coin=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>coin[i];
	}
	int sum;
	cin>>sum;
	
	int answer=coinChange1(coin,n,sum);
	cout<<answer<<endl;
}
