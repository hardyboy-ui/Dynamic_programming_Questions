#include<bits/stdc++.h>
using namespace std;


int countSubsetSum(int *arr,int n,int sum)
{
	int t[100][1000];
	for(int i=0;i<=sum;i++)
	{
		t[0][i]=0;
	}
	for(int i=0;i<=n;i++)
	{
		t[i][0]=1;
	}
	
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
int targetSum(int *arr,int n,int sum,int val)
{
	if(sum%2==0)
	{
		if(val%2!=0)
		{
			return 0;
		}
		else
		{
			return countSubsetSum(arr,n,sum/2-val/2);
		}
	}
	else
	{
		if(val%2==0)
		{
			return 0;
		}
		else
		{
			return countSubsetSum(arr,n,(sum-val)/2);
		}
	}
}
int main()
{
	int n;
	cin>>n;
	int* arr=new int[n];
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
	}
	int val;
	cin>>val;
	int answer=targetSum(arr,n,sum,abs(val));
	cout<<answer<<endl;
	return 0;
}
