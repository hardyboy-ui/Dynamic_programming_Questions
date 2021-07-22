#include<bits/stdc++.h>
using namespace std;

int t[100][1000];
int RodCuttingCost(int* length,int*price,int n,int tLength)
{
	for(int i=0;i<=n;i++)
	{
		t[i][0]=0;
	}
	for(int i=0;i<=tLength;i++)
	{
		t[0][i]=0;
	}
	
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=tLength;j++)
		{
			if(length[i-1]<=j)
			{
				t[i][j]=max(price[i-1]+t[i][j-length[i-1]],t[i-1][j]);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][tLength];
}




/*int RodCuttingCost(int *length,int *price,int n,int tLength)
{
	if(n==0)
	{
		return 0;
	}
	if(tLength<=0)
	{
		return 0;
	}
	
	if(length[n-1]<=tLength)
	{
		int x=RodCuttingCost(length,price,n,tLength-length[n-1]);
		int y=RodCuttingCost(length,price,n-1,tLength);
		return max(x+price[n-1],y);
	}
	else
	{
		return RodCuttingCost(length,price,n-1,tLength);
	}
}*/


int main()
{
	int n;
	cin>>n;
	
	int *length=new int [n];
	for(int i=0;i<n;i++)
	{
		cin>>length[i];
	}
	int *price=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>price[i];
	}

	int answer=RodCuttingCost(length,price,n,n);
	cout<<answer;
}
