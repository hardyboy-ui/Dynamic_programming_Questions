#include <bits/stdc++.h>
using namespace std;

bool t[100][1000];
bool  subsetSum(int *arr,int n,int sum)
{
	for(int i=0;i<=sum;i++)     //initialisation  
	{
		t[0][i]=false;
	}
	for(int  i=0;i<=n;i++)
	{
		t[i][0]=true;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				t[i][j]=(t[i-1][j-arr[i-1]]||t[i-1][j]);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		}
	}
	return t[n][sum];
}


//MEMOIZATION FORM


//int t[10][1000];
/*bool subsetSum(int *arr,int n,int sum)
{
	if(t[n][sum]!=-1)
	{
		if(t[n][sum]==1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	if(sum==0)
	{
		return true;
		
	}
	if(n==0)
	{
		return false;
	}
	
	if(arr[n-1]<=sum)
	{
		bool x=subsetSum(arr,n-1,sum-arr[n-1]);
		bool y=subsetSum(arr,n-1,sum);
		bool answer=(x||y);
		if(answer==true)
		{
			t[n][sum]=1;
		}
		else
		{
			t[n][sum]=0;
		}
		return answer;
	}
	else
	{
		bool answer=subsetSum(arr,n-1,sum);
		if(answer==true)
		{
			t[n][sum]=1;
		}
		else
		{
			t[n][sum]=0;
		}
		return answer;
	}
}*/

//RECURSIVE SOLUTION

/*bool subsetSum(int *arr,int n,int sum)
{
	if(sum==0)
	{
		return true;
		
	}
	if(n==0)
	{
		return false;
	}
	
	if(arr[n-1]<=sum)
	{
		bool x=subsetSum(arr,n-1,sum-arr[n-1]);
		bool y=subsetSum(arr,n-1,sum);
		return (x||y);
	}
	else
	{
		return subsetSum(arr,n-1,sum);
	}
}*/
int main()
{
//	memset(t,-1,sizeof(t));
	int n;
	cin>>n;
	int *arr=new int[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int sum;
	cin>>sum;
	
	bool answer= subsetSum(arr,n,sum);
	
	if(answer==true)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		cout<<"NO"<<endl;
	}
}
