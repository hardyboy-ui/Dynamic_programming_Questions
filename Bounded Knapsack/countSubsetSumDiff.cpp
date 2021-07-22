#include<bits/stdc++.h>
using namespace std;

int countSubsetSum(int *arr,int n,int sum)
{
	int t[100][1000];
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

int countSubsetSumDiff(int *arr,int n,int sum,int diff)
{
	if(sum%2==0)
	{
		if(diff%2==0)
		{
			return countSubsetSum(arr,n,(sum-diff)/2);
		}
		else
		{
			return 0;
		}
	}
	else
	{
		if(diff%2==0)
		{
			return 0;
		}
		else
		{
			return countSubsetSum(arr,n,(sum-diff)/2);
		}
	}
}

int main()
{
	int n;
	cin>>n;
	int *arr=new int[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	int diff;
	cin>>diff;
	int answer=countSubsetSumDiff(arr,n,sum,diff);
	cout<<answer<<endl;
}
