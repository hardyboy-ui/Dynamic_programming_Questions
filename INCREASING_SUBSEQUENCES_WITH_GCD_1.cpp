#include<bits/stdc++.h>
using namespace std;

double func(pair<int,int> *arr, int* fi, int n, int m,double** dp)
{
    if(dp[n][m]!=-1)
    {
        return dp[n][m];
    }
    if(n==0)
    {
        return fi[0];
    }
    if(n==1)
    {
        double d=double(fi[0]);
        long long int x=arr[0].first-arr[m-1].first;
        x=x*x;
        long long int y=arr[0].second-arr[m-1].second;
        y=y*y;
        d=d-sqrt(x+y);
        return d;
    }
    long long int x,y;
    
    x=arr[n-1].first-arr[m-1].first;
    x=x*x;
    y=arr[n-1].second-arr[m-1].second;
    y=y*y;
    double z=sqrt(x+y);
    double answer=func(arr, fi, n-1, m, dp) ;
    
    double answer1=func(arr, fi, n-1, n, dp);
    if(answer1+(double)fi[n-1]-z>answer) 
    {
        answer=answer1+(double)fi[n-1]-z;
    }
    return dp[n][m]=answer;
}
int main(){
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int* fi=new int[n];
        pair<int,int> * arr=new pair<int,int>[n];
        for(int i=0;i<n;i++) 
        {
            cin>>arr[i].first;
            cin>>arr[i].second;
            cin>>fi[i];
        }
        double** dp=new double*[n+1];
        for(int i=0;i<=n;i++)
        {
            dp[i]=new double[n+1];
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        double d=func(arr,fi,n-1,n,dp);
        d=d+double(fi[n-1]);
        cout<<fixed<<setprecision(6)<<d<<endl;
    }
    return 0;
}