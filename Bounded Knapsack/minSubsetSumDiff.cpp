#include<bits/stdc++.h>
using namespace std;

bool t[100][10000];
vector<int> subsetSum(int *arr,int n,int sum)
{
	for(int i=0;i<=sum;i++)
	{
		t[0][i]=false;
	}
	for(int i=0;i<=n;i++)
	{
		t[i][0]=true;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum;j++)
		{
			if(arr[i-1]<=j)
			{
				t[i][j]=t[i-1][j-arr[i-1]]||t[i-1][j];
			}
			else
			{
				t[i][j]=t[i-1][j];
			}

		}
	}
	vector<int> answer;
	for(int i=0;i<=sum/2;i++)     //only considering values less than(<) range /2;
	{
		if(t[n][i]==true)
		{
			answer.push_back(i);
		}
	}
	return answer;
}

int subsetSumDiff(int* arr,int n,int range)
{
	vector<int> answer=subsetSum(arr,n,range);
	int min=INT_MAX;
	for(int i=0;i<answer.size();i++)
	{
		if(range-(2*answer[i])<min)
		{
			min=range-(2*answer[i]);
		}
	}
	return min;
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
	
	
	int answer=subsetSumDiff(arr,n,sum);
	cout<<answer<<endl;
}
