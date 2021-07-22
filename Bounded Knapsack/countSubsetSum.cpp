#include <bits/stdc++.h>
using namespace std;


int t[100][1000];

int countSubsetSum(int *arr,int n,int sum)
{
	
	//intitialisation of t matrix
	for(int i=0;i<=n;i++)
	{
		t[i][0]=1;
	}
	for(int i=0;i<=sum;i++)
	{
		t[0][i]=0;
	}
	t[0][0]=1;  //initialisation when n==0 && sum==0
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][sum];
}
int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	
	int sum;
	cin>>sum;
	int count=countSubsetSum(arr,n,sum);
	cout<<count;
	
}
