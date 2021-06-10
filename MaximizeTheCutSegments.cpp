#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z)
{
    //Your code here
    int dp[n+1]={0};
    
    for(int i=1;i<=n;i++)
    {
        if(i<x)
        {
            dp[i]=dp[i];
        }
        else if(i==x)
        {
            dp[i]=max(1,dp[i]);
        }
        else
        {
            if(dp[i-x]!=0)
                dp[i] = max(1+dp[i-x],dp[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i<y)
        {
            dp[i]=dp[i];
        }
        else if(i==y)
        {
            dp[i]=max(1,dp[i]);
        }
        else
        {
            if(dp[i-y]!=0)
                dp[i] = max(1+dp[i-y],dp[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i<z)
        {
            dp[i]=dp[i];
        }
        else if(i==z)
        {
            dp[i]=max(1,dp[i]);
        }
        else
        {
            if(dp[i-z]!=0)
                dp[i] = max(1+dp[i-z],dp[i]);
        }
    }
    
    return dp[n];
    
}

int main()
{
	int n=5,x=5,y=2,z=3;
	cout<<maximizeTheCuts(n,x,y,z)<<endl;
}